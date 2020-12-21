/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:43:31 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 20:43:40 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <draw_utils.h>

void			spritedistcalc(t_mlx *mlx)
{
	int			i;

	i = 0;
	while (i < mlx->config->spritecount)
	{
		mlx->sprite[i].dist = pow((mlx->player.posx -
							mlx->sprite[i].x), 2) +
							pow((mlx->player.posy -
							mlx->sprite[i].y), 2);
		i++;
	}
}

void			order_sprites(t_mlx *mlx)
{
	int			i;
	int			j;
	t_sprite	tmp;

	spritedistcalc(mlx);
	i = 0;
	while (i < mlx->config->spritecount)
	{
		j = i + 1;
		while (j < mlx->config->spritecount)
		{
			if (mlx->sprite[i].dist < mlx->sprite[j].dist)
			{
				tmp = mlx->sprite[i];
				mlx->sprite[i] = mlx->sprite[j];
				mlx->sprite[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
