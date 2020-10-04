/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:53:04 by mviudes           #+#    #+#             */
/*   Updated: 2020/10/03 13:23:48 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <mlx.h>

void	draw_square(void *mlx, void *win, int posx, int posy, int size, int color)
{

	int		x;
	int		y;

	x = posx;
	y = posy;

	while(y < size + posy)
	{
		x = posx;
		while(x < size +posx)
		{
			mlx_pixel_put(mlx, win, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_line(void *mlx, void *win, int x1, int y1, int x2, int y2, int color)
{
	int slope;
	int x;
	int y;

	slope = (y2 - y1)/(x2 - x1);
	x = x1;
	if (x1 > x2)
	{
		x = x2;
		x2 = x1;
	}
	while (x <= x2)
	{
		y = slope * (x - x1) + y1;
		mlx_pixel_put(mlx, win, x, y, color);
		x++;
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
	offset = 2;
	size = 20;
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

void	draw_player(t_mlx *mlx, t_player *player)
{
	float angle;
	float dirx;
	float diry;

	angle = ft_radians(player->angle);
	dirx = player->posx + cos(angle) * 20;
	diry = player->posy + sin(angle) * 20;
	draw_square(mlx->mlx, mlx->win, player->posx , player->posy, 10 , 0x00FFFFFF);
	draw_line(mlx->mlx, mlx->win, player->posx + 5, player->posy + 5, dirx, diry, 0x00F100FC);
}

int		engine(t_mlx *mlx)
{
	move_player(mlx);
	draw_player(mlx, mlx->player);
	mlx->move.forward = 0;
//	printf("x = %f, y = %f\n", mlx->player->posx, mlx->player->posy);
	draw_map(mlx);
	return (0);
}
int		init_player(t_config *config, t_mlx *mlx)
{
	mlx->player->posx = 300;
	mlx->player->posy = 300;
	mlx->player->angle = 90;
	return (0);
}
void	move_player(t_mlx *mlx)
{
	if(mlx->move.forward == 1)
		mlx->player->posy -= 0.3;
}