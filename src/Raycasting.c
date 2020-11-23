/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:28:41 by mviudes           #+#    #+#             */
/*   Updated: 2020/11/19 14:39:29 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <draw_utils.h>

float	ray_verdist(t_mlx *mlx, double angle){
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
	if(mlx->player.dir.y == 0)
		return(NAN);
	if(mlx->player.dir.x == 0)
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
float	ray_hordist(t_mlx *mlx, double angle){

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
	int	i;

	float disty;
	float distx;
	float walldist;
	int	planex;
	int planey;
	int ray_angle;
	int numrays;
	int lineheight;
	int side;
	int x;
	double angle;

	int firstpix;
	int lastpix;
	planex = mlx->config->resolutionwidht;
	planey = mlx->config->resolutionheight;
	i = 0;
	x = 0;
	angle = atan2f(mlx->player.dir.y, mlx->player.dir.x);
	while(i < planex){
		disty = ray_verdist(mlx, angle);
		distx = ray_hordist(mlx, angle);
		walldist = fminf(disty, distx);
		lineheight = (int)(planex/walldist);

		/*calculate first last pix*/

		firstpix = (-lineheight / 2) + (planey / 2);
		if(firstpix < 0)
			firstpix = 0;
		lastpix = (lineheight / 2) + (planey / 2);
		if(lastpix >= planey)
			lastpix = planey -1;
		/*-------------*/
		
		angle += DEG_RAD;
		//draw_line(mlx, mlx->win, mlx->player.posx + 5, mlx->player.posy + 5, ray_x, ray_y, 	0x00001FFF);
	//	printf("%f	%f   %f\n", ray_x, ray_y, ft_todeg(angle));
		//printf("%f\n", walldist);
		i++;
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