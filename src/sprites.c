/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:57:03 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 20:43:43 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <draw_utils.h>

void			first_spritecalc(t_mlx *mlx, int i)
{
	mlx->spritex = mlx->sprite[i].x - mlx->player.posx;
	mlx->spritey = mlx->sprite[i].y - mlx->player.posy;
	mlx->invdet = 1.0 / (mlx->plane.x *
			mlx->player.dir.y - mlx->player.dir.x * mlx->plane.y);
	mlx->sprt_transfx = mlx->invdet *
					(mlx->player.dir.y * mlx->spritex -
					mlx->player.dir.x * mlx->spritey);
	mlx->sprt_transfy = mlx->invdet * (-mlx->plane.y *
					mlx->spritex + mlx->plane.x * mlx->spritey);
	mlx->sprt_screenx = (int)((mlx->config->resolutionwidth / 2) *
					(1 + mlx->sprt_transfx / mlx->sprt_transfy));
	mlx->sprt_height = abs((int)(mlx->config->resolutionheight /
					(mlx->sprt_transfy)));
}

void			first_lastpix(t_mlx *mlx, int i)
{
	mlx->sprt_firsty = (-mlx->sprt_height / 2) +
					(mlx->config->resolutionheight / 2);
	if (mlx->sprt_firsty < 0)
		mlx->sprt_firsty = 0;
	mlx->sprt_lasty = (mlx->sprt_height / 2) +
					(mlx->config->resolutionheight / 2);
	if (mlx->sprt_lasty >= mlx->config->resolutionheight)
		mlx->sprt_lasty = mlx->config->resolutionheight - 1;
	mlx->sprt_width = abs((int)(mlx->config->resolutionheight /
					(mlx->sprt_transfy)));
	mlx->sprt_firstx = (-mlx->sprt_width / 2) + mlx->sprt_screenx;
	if (mlx->sprt_firstx < 0)
		mlx->sprt_firstx = 0;
	mlx->sprt_lastx = mlx->sprt_width / 2 + mlx->sprt_screenx;
	if (mlx->sprt_lastx > mlx->config->resolutionwidth)
		mlx->sprt_lastx = mlx->config->resolutionwidth - 1;
}

void			calc_texx(t_mlx *mlx, int x, int i)
{
	mlx->sprt_texx = (int)(256 * (x - (-mlx->sprt_width / 2 +
	mlx->sprt_screenx)) *
	mlx->sprite[i].tex.img_width /
	mlx->sprt_width / 256);
}

void			print_wall_tex(t_mlx *mlx, int x, int i)
{
	int			y;

	calc_texx(mlx, x, i);
	y = mlx->sprt_firsty;
	if (mlx->sprt_transfy > 0 && x > 0 && x <
		mlx->config->resolutionwidth &&
		mlx->sprt_transfy < mlx->sprite_buff[x])
		while (y < mlx->sprt_lasty)
		{
			mlx->sprt_texy = ((((y) * 256 -
			mlx->config->resolutionheight * 128 + mlx->sprt_height *
			128) *
			mlx->sprite[i].tex.img_height) / mlx->sprt_height) / 256;
			if (mlx->sprite[i].tex.img_addr[4 * (mlx->sprt_texx +
				64 * mlx->sprt_texy)]
			!= (char)0)
				ft_memcpy(mlx->img_addr + 4 *
				mlx->config->resolutionwidth * y + x * 4,
				&mlx->sprite[i].tex.img_addr
				[mlx->sprt_texy % mlx->sprite[i].tex.img_height *
					mlx->sprite[i].tex.line_lenght + mlx->sprt_texx
					% mlx->sprite[i].tex.img_width
					* mlx->sprite[i].tex.bpp / 8], sizeof(int));
			y++;
		}
}

void			draw_sprites(t_mlx *mlx)
{
	int x;
	int y;
	int i;

	order_sprites(mlx);
	i = 0;
	while (i < mlx->config->spritecount)
	{
		first_spritecalc(mlx, i);
		first_lastpix(mlx, i);
		x = mlx->sprt_firstx;
		while (x < mlx->sprt_lastx)
		{
			print_wall_tex(mlx, x, i);
			x++;
		}
		i++;
	}
	return ;
}
