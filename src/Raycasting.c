/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:28:41 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 18:46:17 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <draw_utils.h>

void		dda_algorithm(t_mlx *mlx, int mapx, int mapy)
{
	while (mlx->ray.hit == 0)
	{
		if (mlx->ray.sidedistx < mlx->ray.sidedisty)
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
		if (mlx->config->map.map[mapx][mapy] == 1)
			mlx->ray.hit = 1;
		if (mlx->config->map.map[mapx][mapy] == 2)
			mlx->enablesprite = 1;
	}
	if (mlx->ray.side == 0)
		mlx->ray.walldist = (mapx - mlx->player.posx + (1 - mlx->ray.stepx) / 2)
							/ mlx->ray.dirx;
	else
		mlx->ray.walldist = (mapy - mlx->player.posy + (1 - mlx->ray.stepy) / 2)
							/ mlx->ray.diry;
}

void		dist_calculation(t_mlx *mlx, int mapx, int mapy)
{
	if (mlx->ray.dirx < 0)
	{
		mlx->ray.stepx = -1;
		mlx->ray.sidedistx = (mlx->player.posx - mapx) * mlx->ray.deltadistx;
	}
	else
	{
		mlx->ray.stepx = 1;
		mlx->ray.sidedistx = (mapx + 1 - mlx->player.posx) *
							mlx->ray.deltadistx;
	}
	if (mlx->ray.diry < 0)
	{
		mlx->ray.stepy = -1;
		mlx->ray.sidedisty = (mlx->player.posy - mapy) * mlx->ray.deltadisty;
	}
	else
	{
		mlx->ray.stepy = 1;
		mlx->ray.sidedisty = (mapy + 1 - mlx->player.posy) *
							mlx->ray.deltadisty;
	}
}

void		wallcalculation(t_mlx *mlx)
{
	int		lineheight;
	int		height;
	int		firstpix;
	int		lastpix;

	height = mlx->config->resolutionheight;
	mlx->ray.walldist = fabs(mlx->ray.walldist);
	lineheight = abs((int)(height / mlx->ray.walldist));
	firstpix = (-lineheight / 2) + (height / 2);
	if (firstpix < 0)
		firstpix = 0;
	lastpix = (lineheight / 2) + (height / 2);
	if (lastpix >= height)
		lastpix = height - 1;
	mlx->lineheight = lineheight;
	mlx->firstpix = firstpix;
	mlx->lastpix = lastpix;
}

void		firstraycalc(t_mlx *mlx, int x)
{
	double	camerax;

	camerax = 2 * x / (double)mlx->config->resolutionwidth - 1;
	mlx->ray.dirx = mlx->player.dir.x + mlx->plane.x * camerax;
	mlx->ray.diry = mlx->player.dir.y + mlx->plane.y * camerax;
	if (mlx->ray.diry == 0)
		mlx->ray.deltadistx = 0;
	else
	{
		if (mlx->ray.dirx == 0)
			mlx->ray.deltadistx = 1;
		else
			mlx->ray.deltadistx = fabs(1 / mlx->ray.dirx);
	}
	if (mlx->ray.dirx == 0)
		mlx->ray.deltadisty = 0;
	else
	{
		if (mlx->ray.diry == 0)
			mlx->ray.deltadisty = 1;
		else
			mlx->ray.deltadisty = fabs(1 / mlx->ray.diry);
	}
}

void		raycasting(t_mlx *mlx)
{
	int mapx;
	int mapy;
	int width;
	int height;

	mlx->x = 0;
	width = mlx->config->resolutionwidth;
	height = mlx->config->resolutionheight;
	while (mlx->x < width)
	{
		mlx->ray.hit = 0;
		mlx->lineheight = 0;
		mapx = mlx->player.mapx;
		mapy = mlx->player.mapy;
		firstraycalc(mlx, mlx->x);
		dist_calculation(mlx, mapx, mapy);
		dda_algorithm(mlx, mapx, mapy);
		wallcalculation(mlx);
		draw_verline(mlx, 0, mlx->firstpix, mlx->ceilcolor);
		draw_verline(mlx, mlx->lastpix + 1, height - 1, mlx->floorcolor);
		print_texture(mlx, height, width, mlx->x);
		mlx->sprite_buff[mlx->x] = mlx->ray.walldist;
		mlx->x++;
	}
}
