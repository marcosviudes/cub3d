/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:45:51 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 19:10:26 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <draw_utils.h>

void		print_texture(t_mlx *mlx, int height, int width, int x)
{
	int		i;
	int		id;
	int		tex_y;
	int		tex_x;
	double	wallx;

	i = mlx->firstpix;
	id = get_text_id(mlx->ray.side, mlx->ray.dirx, mlx->ray.diry);
	if (mlx->ray.side == 0)
		wallx = mlx->player.posy + (mlx->ray.walldist * mlx->ray.diry);
	else
		wallx = mlx->player.posx + (mlx->ray.walldist * mlx->ray.dirx);
	wallx -= floor(wallx);
	tex_x = (int)(wallx * (64));
	while (i <= mlx->lastpix)
	{
		tex_y = abs((((i * 256 - height * 128 + mlx->lineheight * 128)
					* 64) / mlx->lineheight) / 256);
		ft_memcpy(mlx->img_addr + 4 * width * i + x * 4,
		&mlx->tex[id].img_addr[tex_y % mlx->tex[id].img_height *
								mlx->tex[id].line_lenght + tex_x %
								mlx->tex[id].img_width *
								mlx->tex[id].bpp / 8], sizeof(int));
		i++;
	}
}

int			get_text_id(int side, float dirx, float diry)
{
	if (side == 0)
	{
		if (dirx > 0)
			return (2);
		else
			return (1);
	}
	else
	{
		if (diry > 0)
			return (0);
		else
			return (3);
	}
}
