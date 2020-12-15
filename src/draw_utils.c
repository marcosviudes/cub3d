/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:53:04 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/15 13:29:13 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <mlx.h>

void            my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char    *dst;

    dst = mlx->img_addr + (y * mlx->line_lenght + x * (mlx->bpp / 8));
    *(unsigned int*)dst = color;
}

void	draw_square(t_mlx *mlx, void *win, int posx, int posy, int size, int color)
{

	int		x;
	int		y;

	x = posx;
	y = posy;

	while(y < size + posy)
	{
		x = posx;
		while(x < size + posx)
		{
			my_mlx_pixel_put(mlx, x, y, color);
			x++;
		}
		y++;
	}
}

void draw_line(t_mlx *mlx, void *win,int x1, int y1, int x2, int y2,int color)
{
  int i,dx,dy,sdx,sdy,dxabs,dyabs,x,y,px,py;

  dx=x2-x1;      
  dy=y2-y1;
  dxabs=abs(dx);
  dyabs=abs(dy);
  sdx=ft_sign(dx);
  sdy=ft_sign(dy);
  x=dyabs>>1;
  y=dxabs>>1;
  px=x1;
  py=y1;

  if (dxabs>=dyabs)
  {
    for(i=0;i<dxabs;i++)
    {
      y+=dyabs;
      if (y>=dxabs)
      {
        y-=dxabs;
        py+=sdy;
      }
      px+=sdx;
		my_mlx_pixel_put(mlx, px, py, color);
    }
  }
  else 
  {
    for(i=0;i<dyabs;i++)
    {
      x+=dxabs;
      if (x>=dyabs)
      {
        x-=dyabs;
        px+=sdx;
      }
      py+=sdy;
	  my_mlx_pixel_put(mlx, px, py, color);
    }
  }
}
void draw_verline(t_mlx *mlx, void *win,int x, int y1,int y2,int color){
	int y;
	
	y = y1;
	while(y < y2)
	{
		my_mlx_pixel_put(mlx, x, y, color);
		y++;
	}
}

int	draw_map(t_mlx *mlx)
{
	int		i;
	int		j;
	int		offset;
	int		posx;
	int		posy;
	int		size;
	int 	widht;
	int		height;
	
	widht = mlx->config->map.max_widht;
	height = mlx->config->map.max_height;
	j = 0;
	posy = 0;
	posx = 0;
	offset = 0;
	size = 10;
	while (j < height)
	{
		i = 0;
		posx = 0;
		while ( i < widht)
		{
			if (mlx->config->map.map[j][i] == 0)
				draw_square(mlx, mlx->win, posx , posy, size , 0x00FFFFFF);
			else if (mlx->config->map.map[j][i] == 1)
				draw_square(mlx, mlx->win, posx, posy, size , 0x00CE472C);
			else if (mlx->config->map.map[j][i] == 2)
				draw_square(mlx, mlx->win, posx, posy, size , 0x0035FC00);
			posx = size + offset + posx;
			i++;
		}
		j++;
		posy = size + offset + posy;
	}
	return 0;
}

void	draw_player(t_mlx *mlx)
{
	int draw_posx = mlx->player.posy;
	int draw_posy = mlx->player.posx;
	draw_square(mlx, mlx->win,draw_posx , draw_posy, 10, 0x00000000);
	//draw_line(mlx, mlx->win, mlx->player.posx + 5 , mlx->player.posy + 5 , (int)xdir, (int)ydir, 0x00F100FC);
}

int		engine(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, mlx->config->resolutionwidht, mlx->config->resolutionheight);
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_lenght, &mlx->endian);
	mlx->player.mapx = (int)mlx->player.posx;
	mlx->player.mapy = (int)mlx->player.posy;
	move_player(mlx);
	raycasting(mlx);
	if(mlx->enablesprite)
		draw_sprites(mlx);
	//draw_map(mlx);
	//draw_player(mlx);
	//printf("x = %f, y = %f,\n", mlx->player.posx, mlx->player.posy);
	//printf("%f , %f\n", mlx->player.dir.x, mlx->player.dir.y);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

void	start_dir(char init_dir, t_mlx *mlx){
	if(init_dir == 'N'){
		mlx->player.dir.x = -1.0;
		mlx->player.dir.y = 0.0;
		mlx->plane.x = 0.0;
		mlx->plane.y = 0.66;
	}
	else if(init_dir == 'S'){
		mlx->player.dir.x = 1.0;
		mlx->player.dir.y = 0.0;
		mlx->plane.x = 0.0;
		mlx->plane.y = -0.66;
	}
	else if(init_dir == 'W'){
		mlx->player.dir.x = 0.0;
		mlx->player.dir.y = -1.0;
		mlx->plane.x = -0.66;
		mlx->plane.y = 0.0;
	}
	else if(init_dir == 'E'){
		mlx->player.dir.x = 0.0;
		mlx->player.dir.y = 1.0;
		mlx->plane.x = 0.66;
		mlx->plane.y = 0.0;
	}
}

int		init_player(t_config *config, t_mlx *mlx)
{
	int i;
	start_dir(config->init_dir, mlx);
	mlx->player.speed = MOV_DEF * MOV_SPEED;
	mlx->player.mapx = mlx->config->init_pos.x;
	mlx->player.mapy = mlx->config->init_pos.y;
	mlx->player.posx = mlx->player.mapx + 0.5;
	mlx->player.posy = mlx->player.mapy + 0.5;
	i = 0;
	mlx->sprite_buff = (double *)malloc(sizeof(double) * mlx->config->resolutionwidht);
	while(i < mlx->config->spritecount)
		{
			mlx->sprite[i].tex = mlx->tex[4];
			i++;
		}
	
	return (0);
}
void	move_player(t_mlx *mlx)
{
	double speed;
	
	speed = mlx->player.speed;
	if(mlx->move.forward == 1){
		if(mlx->config->map.map[(int)(mlx->player.posx + mlx->player.dir.x * speed)][mlx->player.mapy] != 1)
			mlx->player.posx += mlx->player.dir.x * speed;
		if(mlx->config->map.map[mlx->player.mapx][(int)(mlx->player.posy + mlx->player.dir.y * speed)] != 1)
			mlx->player.posy += mlx->player.dir.y * speed;
	}
	if(mlx->move.backwards == 1){
		if(mlx->config->map.map[(int)(mlx->player.posx - mlx->player.dir.x * speed)][mlx->player.mapy] != 1)
			mlx->player.posx -= mlx->player.dir.x * speed;
		if(mlx->config->map.map[mlx->player.mapx][(int)(mlx->player.posy - mlx->player.dir.y * speed)] != 1)
			mlx->player.posy -= mlx->player.dir.y * speed;
	}
	if(mlx->move.left == 1){
		if(mlx->config->map.map[(int)(mlx->player.posx - mlx->player.dir.y * speed)][mlx->player.mapy] != 1)
			mlx->player.posx -= mlx->player.dir.y * speed;
		if(mlx->config->map.map[mlx->player.mapx][(int)(mlx->player.posy + mlx->player.dir.x * speed)] != 1)
			mlx->player.posy += mlx->player.dir.x * speed;
	}
	if(mlx->move.right == 1){
		if(mlx->config->map.map[(int)(mlx->player.posx + mlx->player.dir.y * speed)][mlx->player.mapy] != 1)
			mlx->player.posx += mlx->player.dir.y * speed;
		if(mlx->config->map.map[mlx->player.mapx][(int)(mlx->player.posy - mlx->player.dir.x * speed)] != 1)
			mlx->player.posy -= mlx->player.dir.x * speed;
	}
	if(mlx->move.rotright == 1)
	{
		mlx->player.lastdir.x = mlx->player.dir.x;
		mlx->player.lastdir.y = mlx->player.dir.y;
		mlx->player.dir.x = mlx->player.dir.x * cos(-ROT_CONST) - mlx->player.dir.y * sin(-ROT_CONST);
		mlx->player.dir.y = mlx->player.lastdir.x * sin(-ROT_CONST) + mlx->player.dir.y * cos(-ROT_CONST);
		mlx->plane.oldx = mlx->plane.x;
		mlx->plane.oldy = mlx->plane.y;
		mlx->plane.x = mlx->plane.x * cos(-ROT_CONST) - mlx->plane.y * sin(-ROT_CONST);
		mlx->plane.y = mlx->plane.oldx * sin(-ROT_CONST) + mlx->plane.y * cos(-ROT_CONST);
	}
	if(mlx->move.rotleft == 1)
	{
		mlx->player.lastdir.x = mlx->player.dir.x;
		mlx->player.lastdir.y = mlx->player.dir.y;
		mlx->player.dir.x = mlx->player.dir.x * cos(ROT_CONST) - mlx->player.dir.y * sin(ROT_CONST);
		mlx->player.dir.y = mlx->player.lastdir.x * sin(ROT_CONST) + mlx->player.dir.y * cos(ROT_CONST);
		mlx->plane.oldx = mlx->plane.x;
		mlx->plane.x = mlx->plane.x * cos(ROT_CONST) - mlx->plane.y * sin(ROT_CONST);
		mlx->plane.y = mlx->plane.oldx * sin(ROT_CONST) + mlx->plane.y * cos(ROT_CONST);
	}
		//printf("%f , %f\n", mlx->player.dir.x, mlx->player.dir.y);
	//	float angle = atan2f(mlx->player.dir.y, mlx->player.dir.x) * 180/M_PI;
//	printf("%f	%f\n", mlx->player.posx, mlx->player.posy);
	//printf("%d	%d\n", mlx->player.mapx, mlx->player.mapy);
	//	printf("%i\n", (int)angle);
}
//printf("%i\n", (int)atan2f(mlx->player.dir.x, mlx->player.dir.y) * 180/M_PI);

int		get_text_id(int side, float dirx, float diry){
	if(side == 0){
			if(dirx > 0)
				return(0);
			else
				return(1);
		}
		else
		{
			if(diry > 0)
				return(2);
			else
				return(3);
		}
}