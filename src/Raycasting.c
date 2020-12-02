/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:28:41 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/02 12:58:17 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <draw_utils.h>
/*
float	ray_hordist(t_mlx *mlx, double angle){
	float dist;
	double ray_x;
	double ray_y;
	double ya_dist;
	double xa_dist;
	int	mapx;
	int	mapy;
	int hit;

	hit = 0;

//	angle = atan2f(mlx->player.dir.y, mlx->player.dir.x);
	if(fabs(mlx->player.dir.y) < 0.00001)
		return(NAN);
	if(mlx->player.dir.y IS_UP){
		ray_y = floor(mlx->player.posy/CHUNK_SIZE) * (CHUNK_SIZE) - 1;
		ya_dist = -CHUNK_SIZE;
		xa_dist = CHUNK_SIZE/tan(angle);
	}
	if(mlx->player.dir.y IS_DOWN){
		ray_y = floor(mlx->player.posy/CHUNK_SIZE) * CHUNK_SIZE + CHUNK_SIZE;
		ya_dist = CHUNK_SIZE;
		xa_dist = CHUNK_SIZE/-tan(angle);
	}
	
	ray_x = mlx->player.posx + (mlx->player.posy - ray_y)/tan(angle);
	mapx = mlx->player.posx /CHUNK_SIZE;
	mapy = mlx->player.posy /CHUNK_SIZE;
	while(hit != 1){
		mapx = ray_x/CHUNK_SIZE;
		mapy = ray_y/CHUNK_SIZE;
		if (mapx < 0||mapy <0 || mapx > mlx->config->map.max_widht)
			return(NAN);
		if(mlx->config->map.map[mapy][mapx] == 1){
			hit = 1;
			break;
		}
		ray_x += xa_dist;
		ray_y += ya_dist;
	}
	dist = fabs((mlx->player.posx - ray_x)/cos(angle));
	draw_line(mlx, mlx->win, mlx->player.posx + 5, mlx->player.posy + 5, ray_x, ray_y, 	0x00001FFF);
	if(dist < 0)
		return(0);
	return(dist);
}
float	ray_verdist(t_mlx *mlx, double angle){

	float dist;
	double ray_x;
	double ray_y;
	double ya_dist;
	double xa_dist;
	int	mapx;
	int	mapy;
	int paso;
	int hit = 0;
	//angle = atan2f(mlx->player.dir.y, mlx->player.dir.x);
	if(mlx->player.dir.y == 0)
		return(NAN);
	if(mlx->player.dir.x IS_RIGHT){
		ray_x = floor(mlx->player.posx/CHUNK_SIZE) * (CHUNK_SIZE) + CHUNK_SIZE;
		xa_dist = CHUNK_SIZE;
		ya_dist = CHUNK_SIZE * -tan(angle);
	}
	if(mlx->player.dir.x IS_LEFT){
		ray_x = floor(mlx->player.posx/CHUNK_SIZE) * CHUNK_SIZE - 1;
		xa_dist = -CHUNK_SIZE;
		ya_dist = CHUNK_SIZE * tan(angle);
	}
	ray_y = mlx->player.posy + (mlx->player.posx - ray_x) * tan(angle);
	mapx = mlx->player.posx /CHUNK_SIZE;
	mapy = mlx->player.posy /CHUNK_SIZE;
	mapx = ray_x/CHUNK_SIZE;
	mapy = ray_y/CHUNK_SIZE;
	if (mapx < 0||mapy < 0 )
		return(NAN);
	paso = 0;
	while(paso <= mlx->config->map.max_height ){
			mapx = ray_x/CHUNK_SIZE;
			mapy = ray_y/CHUNK_SIZE;
		if (mapx <= 0||mapy <0 || mapy >= mlx->config->map.max_height)
			return(NAN);
		if(mlx->config->map.map[mapy][mapx] == 1){
			hit = 1;
			break;}
		ray_x += xa_dist;
		ray_y += ya_dist;
	}
	draw_line(mlx, mlx->win, mlx->player.posx + 5, mlx->player.posy + 5, ray_x, ray_y, 	0x00E80E67);
	dist = fabs((mlx->player.posx - ray_x)/cos(angle));
	if(dist < 0)
		return(0);
	return(dist);
}
void	raycasting(t_mlx *mlx){
	return;
}*/

void	raycasting(t_mlx *mlx){
	int	i;
	int color;
	double camerax;
	float disty;
	float distx;
	float walldist;
	int ray_angle;
	int numrays;
	int lineheight;
	int side;
	int x;
	double angle;
	int mapx;
	int mapy;
	int firstpix;
	int lastpix;
	int widht = mlx->config->resolutionwidht;
	int height = mlx->config->resolutionheight;
	i = 0;
	x = 1;
	angle = atan2f(mlx->player.dir.y, mlx->player.dir.x);
	angle = angle + 30 * DEG_RAD;
	while(x < widht){
		/*ray position and direction*/
		mapx =  mlx->player.mapx;
		mapy =  mlx->player.mapy;
		camerax = (2 * x / (double)widht) - 1;
		mlx->ray.dirx = mlx->player.dir.x + mlx->plane.x * camerax;
		mlx->ray.diry = mlx->player.dir.y + mlx->plane.y * camerax;
		mlx->ray.deltadistx = fabs(1 / mlx->ray.dirx);
		mlx->ray.deltadisty = fabs(1 / mlx->ray.diry);
		mlx->ray.hit = 0;
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
			if(mlx->config->map.map[mapy][mapx] > 0)
			//draw_line(mlx, mlx->win, mlx->player.posx + 5, mlx->player.posy + 5, mlx->ray.sidedistx, mlx->ray.sidedisty, 0x0004FF00);
				mlx->ray.hit = 1;
		}
		/*DDA Distance*/

		if(mlx->ray.side == 0){
			mlx->ray.walldist = (mapx - mlx->player.posx + (1 - mlx->ray.stepx)/2) / mlx->ray.dirx;
		}
		else
			mlx->ray.walldist = (mapy - mlx->player.posy + (1 - mlx->ray.stepy)/2) / mlx->ray.diry;

		//printf("%f\n", mlx->ray.walldist);
		/*wall calculation*/
		/*calculate first last pix*/
		lineheight = (int)(height / mlx->ray.walldist);
		lineheight *= DEF_HIGHT;
		firstpix = (-lineheight / 2) + (height / 2);
		if(firstpix < 0)
			firstpix = 0;
		lastpix = (lineheight / 2) + (height / 2);
		if(lastpix >= height)
			lastpix = height - 1;
		draw_line(mlx, mlx->win,x,0,x, firstpix, 0x0002EFD9);
		if(mlx->ray.side == 0){
			if(mlx->player.dir.y > 0)
				color = BLUE;
			else
				color = RED;
		}
		else
		{
			if(mlx->player.dir.x > 0)
				color = GREEN;
			else
				color = PINK;
		}
		draw_line(mlx, mlx->win,x, lastpix, x, firstpix, color);
		/*-------------*/
	//	printf("%f\n", walldist);
		//draw_line(mlx, mlx->win, mlx->player.posx + 5, mlx->player.posy + 5, ray_x, ray_y, 	0x00001FFF);
	//	printf("%f	%f   %f\n", ray_x, ray_y, ft_todeg(angle));
		//printf("%f\n", walldist);
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
	if(key == KEY_ESC){
		system("leaks cub3D");
		exit(EXIT_SUCCESS);
	}
	return (0);
}