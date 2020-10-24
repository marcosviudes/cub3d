/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:28:41 by mviudes           #+#    #+#             */
/*   Updated: 2020/10/22 14:48:01 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <draw_utils.h>

void	raycasting(t_mlx *mlx){
	int	i;
	double ray_x;
	double ray_y;
	double ya_dist;
	double xa_dist;
	int	mapx;
	int	mapy;

	double angle;

	angle = atan2f(mlx->player.dir.y, mlx->player.dir.x);
	i = 0;
	while(i < 1){
		/*if(mlx->player.dir.y > 0){
			ray_y = floor(mlx->player.posy/CHUNK_SIZE) * (CHUNK_SIZE) - 1;
			ya_dist = -CHUNK_SIZE;
		}
		if(mlx->player.dir.y < 0){
			ray_y = floor(mlx->player.posy/CHUNK_SIZE) * CHUNK_SIZE + CHUNK_SIZE;
			ya_dist = CHUNK_SIZE;
		}
		xa_dist = CHUNK_SIZE/tan(angle);
		ray_x = mlx->player.posx + (mlx->player.posy - ray_y)/tan(angle);
		mapx = mlx->player.posx /CHUNK_SIZE;
		mapy = mlx->player.posy /CHUNK_SIZE;
		while(mlx->config->map.map[mapy][mapx] != 1){
			ray_x += xa_dist;
			ray_y += ya_dist;
			mapx = ray_x/CHUNK_SIZE;
			mapy = ray_y/CHUNK_SIZE;
		}*/
		if(mlx->player.dir.x > 0){
			ray_x = floor(mlx->player.posx/CHUNK_SIZE) * (CHUNK_SIZE) - 1;
			ya_dist = -CHUNK_SIZE;
		}
		if(mlx->player.dir.x < 0){
			ray_x = floor(mlx->player.posx/CHUNK_SIZE) * CHUNK_SIZE + CHUNK_SIZE;
			ya_dist = CHUNK_SIZE;
		}
		xa_dist = CHUNK_SIZE/tan(angle);
		ray_y = mlx->player.posy + (mlx->player.posx - ray_x)/tan(angle);
		mapx = mlx->player.posx /CHUNK_SIZE;
		mapy = mlx->player.posy /CHUNK_SIZE;
		while(mlx->config->map.map[mapy][mapx] != 1){
			ray_x += xa_dist;
			ray_y += ya_dist;
			mapx = ray_x/CHUNK_SIZE;
			mapy = ray_y/CHUNK_SIZE;
		}
		draw_line(mlx, mlx->win, mlx->player.posx + 5, mlx->player.posy + 5, ray_x, ray_y, 	0x00001FFF);
		printf("%f	%f   %f\n", ray_x, ray_y, ft_todeg(angle));
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