/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:09:12 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 19:10:11 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <draw_utils.h>

int				init_player(t_config *config, t_mlx *mlx)
{
	int			i;

	start_dir(config->init_dir, mlx);
	mlx->player.speed = MOV_DEF * MOV_SPEED;
	mlx->player.mapx = mlx->config->init_pos.x;
	mlx->player.mapy = mlx->config->init_pos.y;
	mlx->player.posx = mlx->player.mapx + 0.5;
	mlx->player.posy = mlx->player.mapy + 0.5;
	i = 0;
	mlx->sprite_buff = (double *)malloc(sizeof(double) *
						mlx->config->resolutionwidth);
	while (i < mlx->config->spritecount)
	{
		mlx->sprite[i].tex = mlx->tex[4];
		i++;
	}
	return (0);
}
