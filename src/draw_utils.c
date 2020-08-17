/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:53:04 by mviudes           #+#    #+#             */
/*   Updated: 2020/08/17 10:22:48 by mviudes          ###   ########.fr       */
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
	size = 40;
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

void	draw_player(t_mlx *mlx, float posx, float posy, float dir)
{
	draw_square(mlx->mlx, mlx->win,mlx->player.posx , mlx->player.posy, 10 , 0x00FFFFFF);
}
void	engine(t_mlx *mlx)
{
	draw_map(mlx);

}