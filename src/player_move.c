/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:06:16 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 19:25:33 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <mlx.h>

void			move_player(t_mlx *mlx)
{
	double		speed;

	speed = mlx->player.speed;
	player_movforward(mlx, speed);
	player_movback(mlx, speed);
	player_movleft(mlx, speed);
	player_movright(mlx, speed);
	player_rotright(mlx);
	player_rotleft(mlx);
}

void			player_rotleft(t_mlx *mlx)
{
	if (mlx->move.rotleft == 1)
	{
		mlx->player.lastdir.x = mlx->player.dir.x;
		mlx->player.lastdir.y = mlx->player.dir.y;
		mlx->player.dir.x = mlx->player.dir.x * cos(ROT_CONST) -
							mlx->player.dir.y * sin(ROT_CONST);
		mlx->player.dir.y = mlx->player.lastdir.x * sin(ROT_CONST) +
							mlx->player.dir.y * cos(ROT_CONST);
		mlx->plane.oldx = mlx->plane.x;
		mlx->plane.x = mlx->plane.x * cos(ROT_CONST) -
						mlx->plane.y * sin(ROT_CONST);
		mlx->plane.y = mlx->plane.oldx * sin(ROT_CONST) +
						mlx->plane.y * cos(ROT_CONST);
	}
}
