/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:53:04 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 19:09:41 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <mlx.h>

void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char		*dst;

	dst = mlx->img_addr + (y * mlx->line_lenght + x * (mlx->bpp / 8));
	*(unsigned int*)dst = color;
}

void			draw_verline(t_mlx *mlx, int y1, int y2, int color)
{
	int y;

	y = y1;
	while (y < y2)
	{
		my_mlx_pixel_put(mlx, mlx->x, y, color);
		y++;
	}
}

int				engine(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, mlx->config->resolutionwidth,
							mlx->config->resolutionheight);
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->bpp,
							&mlx->line_lenght, &mlx->endian);
	mlx->player.mapx = (int)mlx->player.posx;
	mlx->player.mapy = (int)mlx->player.posy;
	move_player(mlx);
	raycasting(mlx);
	if (mlx->enablesprite)
		draw_sprites(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img);
	return (0);
}

void			start_dir(char init_dir, t_mlx *mlx)
{
	if (init_dir == 'N')
	{
		mlx->player.dir.x = -1.0;
		mlx->player.dir.y = 0.0;
		mlx->plane.x = 0.0;
		mlx->plane.y = 0.66;
	}
	else if (init_dir == 'S')
	{
		mlx->player.dir.x = 1.0;
		mlx->player.dir.y = 0.0;
		mlx->plane.x = 0.0;
		mlx->plane.y = -0.66;
	}
	star_dir2(init_dir, mlx);
}

void			star_dir2(char init_dir, t_mlx *mlx)
{
	if (init_dir == 'W')
	{
		mlx->player.dir.x = 0.0;
		mlx->player.dir.y = -1.0;
		mlx->plane.x = -0.66;
		mlx->plane.y = 0.0;
	}
	else if (init_dir == 'E')
	{
		mlx->player.dir.x = 0.0;
		mlx->player.dir.y = 1.0;
		mlx->plane.x = 0.66;
		mlx->plane.y = 0.0;
	}
}
