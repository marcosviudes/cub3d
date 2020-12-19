/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:28:41 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/19 11:18:11 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <draw_utils.h>

void	raycasting(t_mlx *mlx){
	int	i;
	int id;
	int color;
	double camerax;
	int lineheight;
	int x;
	int mapx;
	int mapy;
	int firstpix;
	int lastpix;
	int widht = mlx->config->resolutionwidht;
	int height = mlx->config->resolutionheight;
	i = 0;
	x = 0;

	while(x < widht){
		/*ray position and direction*/
		mapx =  mlx->player.mapx;
		mapy =  mlx->player.mapy;
		camerax = 2 * x / (double)widht - 1;
		mlx->ray.dirx = mlx->player.dir.x + mlx->plane.x * camerax;
		mlx->ray.diry = mlx->player.dir.y + mlx->plane.y * camerax;

		mlx->ray.deltadistx = (mlx->ray.diry == 0) ? 0 : ((mlx->ray.dirx == 0) ? 1 : fabs(1 / mlx->ray.dirx));
      	mlx->ray.deltadisty = (mlx->ray.dirx == 0) ? 0 : ((mlx->ray.diry == 0) ? 1 : fabs(1 / mlx->ray.diry));
		mlx->ray.hit = 0;
		lineheight = 0;
		/*Dist calculation*/

		if(mlx->ray.dirx < 0)
		{
			mlx->ray.stepx = -1;
			mlx->ray.sidedistx = (mlx->player.posx - mapx) * mlx->ray.deltadistx;
		}
		else
		{
			mlx->ray.stepx = 1;
			mlx->ray.sidedistx = (mapx + 1.0 - mlx->player.posx) * mlx->ray.deltadistx;	
		}
		if(mlx->ray.diry < 0)
		{
			mlx->ray.stepy = -1;
			mlx->ray.sidedisty = (mlx->player.posy - mapy) * mlx->ray.deltadisty;
		}
		else
		{
			mlx->ray.stepy = 1;
			mlx->ray.sidedisty = (mapy + 1.0 - mlx->player.posy) * mlx->ray.deltadisty;	
		}
		/*-----------------*/
		/*DDA*/
		while(mlx->ray.hit == 0){
			if(mlx->ray.sidedistx < mlx->ray.sidedisty)
			{
				mlx->ray.sidedistx += mlx->ray.deltadistx;
				mapx += mlx->ray.stepx;
				mlx->ray.side = 0;
			}
			else
			{
				mlx->ray.sidedisty += mlx->ray.deltadisty;
				mapy += mlx->ray.stepy;
				mlx->ray.side = 1;
			}
			if(mlx->config->map.map[mapx][mapy] == 1)
				mlx->ray.hit = 1;
			if(mlx->enablesprite == 0 &&
					mlx->config->map.map[mapx][mapy] == 2)
					mlx->enablesprite = 1;
		}
		/*DDA Distance*/
	
		if(mlx->ray.side == 0){
			mlx->ray.walldist = (mapx - mlx->player.posx + (1 - mlx->ray.stepx)/2) / mlx->ray.dirx;
		}
		else{
			mlx->ray.walldist = (mapy - mlx->player.posy + (1 - mlx->ray.stepy)/2) / mlx->ray.diry;
		}
		mlx->ray.walldist = fabs(mlx->ray.walldist);
		/*wall calculation*/
		/*calculate first last pix*/
		lineheight = abs((int)(height / mlx->ray.walldist));
		//lineheight *= DEF_HIGHT;
		firstpix = (-lineheight / 2) + (height / 2);
		if(firstpix < 0)
			firstpix = 0;
		lastpix = (lineheight / 2) + (height / 2);
		if(lastpix >= height)
			lastpix = height - 1;

		draw_verline(mlx, mlx->win, x, 0, firstpix,  mlx->ceilcolor);
		draw_verline(mlx, mlx->win, x, lastpix + 1, height -1, mlx->floorcolor);

		//Wall color
		if(mlx->ray.side == 0){
			if(mlx->ray.dirx > 0)
				color = BLUE;
			else
				color = RED;
		}
		else
		{
			if(mlx->ray.diry> 0)
				color = GREEN;
			else
				color = PINK;
		}
		draw_line(mlx, mlx->win,x, firstpix, x, lastpix, color);
		/*-------------*/
		
		i= firstpix;
		int tex_y;
		int tex_x;
		double temp;
		double wallx;
		
		id = get_text_id(mlx->ray.side, mlx->ray.dirx, mlx->ray.diry);
		if (mlx->ray.side == 0) 
			wallx = mlx->player.posy + (mlx->ray.walldist * mlx->ray.diry);
      	else           
		  	wallx = mlx->player.posx + (mlx->ray.walldist * mlx->ray.dirx);
		wallx -= floor(wallx);
		tex_x = (int)(wallx * (64));
		while (i <= lastpix)
		{
		tex_y = abs((((i * 256 - height * 128 +
						 lineheight * 128)
						  * 64) /
						  lineheight) / 
						  256);
		ft_memcpy(mlx->img_addr + 4 * widht * i + x * 4,
			&mlx->tex[id].img_addr[tex_y % mlx->tex[id].img_height * mlx->tex[id].line_lenght + tex_x % mlx->tex[id].img_widht * mlx->tex[id].bpp / 8], sizeof(int));
			i++;
		}
		mlx->sprite_buff[x] = mlx->ray.walldist;
		x++;
	}
}

int	press_key(int	key, t_mlx *mlx)
{
	if(key == KEY_W)
		mlx->move.forward = 1;
	if(key == KEY_S)
		mlx->move.backwards= 1;
	if(key == KEY_A)
		mlx->move.left = 1;
	if(key == KEY_D)
		mlx->move.right = 1;
	if(key == KEY_LEFT)
		mlx->move.rotleft = 1;
	if(key == KEY_RIGHT)
		mlx->move.rotright= 1;
	return(0);
}
int release_key(int key, t_mlx *mlx)
{
	if(key == KEY_W)
		mlx->move.forward = 0;
	if(key == KEY_S)
		mlx->move.backwards= 0;
	if(key == KEY_A)
		mlx->move.left = 0;
	if(key == KEY_D)
		mlx->move.right = 0;
	if(key == KEY_LEFT)
		mlx->move.rotleft = 0;
	if(key == KEY_RIGHT)
		mlx->move.rotright= 0;
	if(key == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}