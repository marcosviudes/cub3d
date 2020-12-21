/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:21:46 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 19:25:58 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <mlx.h>

void			player_movforward(t_mlx *mlx, double speed)
{
	if (mlx->move.forward == 1)
	{
		if (mlx->config->map.map
			[(int)(mlx->player.posx + mlx->player.dir.x * speed)]
			[mlx->player.mapy] != 1)
			mlx->player.posx += mlx->player.dir.x * speed;
		if (mlx->config->map.map
			[mlx->player.mapx]
			[(int)(mlx->player.posy + mlx->player.dir.y * speed)] != 1)
			mlx->player.posy += mlx->player.dir.y * speed;
	}
}

void			player_movback(t_mlx *mlx, double speed)
{
	if (mlx->move.backwards == 1)
	{
		if (mlx->config->map.map
			[(int)(mlx->player.posx - mlx->player.dir.x * speed)]
			[mlx->player.mapy] != 1)
			mlx->player.posx -= mlx->player.dir.x * speed;
		if (mlx->config->map.map
			[mlx->player.mapx]
			[(int)(mlx->player.posy - mlx->player.dir.y * speed)] != 1)
			mlx->player.posy -= mlx->player.dir.y * speed;
	}
}

void			player_movleft(t_mlx *mlx, double speed)
{
	if (mlx->move.left == 1)
	{
		if (mlx->config->map.map
			[(int)(mlx->player.posx - mlx->player.dir.y * speed)]
			[mlx->player.mapy] != 1)
			mlx->player.posx -= mlx->player.dir.y * speed;
		if (mlx->config->map.map
			[mlx->player.mapx]
			[(int)(mlx->player.posy + mlx->player.dir.x * speed)] != 1)
			mlx->player.posy += mlx->player.dir.x * speed;
	}
}

void			player_movright(t_mlx *mlx, double speed)
{
	if (mlx->move.right == 1)
	{
		if (mlx->config->map.map
			[(int)(mlx->player.posx + mlx->player.dir.y * speed)]
			[mlx->player.mapy] != 1)
			mlx->player.posx += mlx->player.dir.y * speed;
		if (mlx->config->map.map
			[mlx->player.mapx]
			[(int)(mlx->player.posy - mlx->player.dir.x * speed)] != 1)
			mlx->player.posy -= mlx->player.dir.x * speed;
	}
}

void			player_rotright(t_mlx *mlx)
{
	if (mlx->move.rotright == 1)
	{
		mlx->player.lastdir.x = mlx->player.dir.x;
		mlx->player.lastdir.y = mlx->player.dir.y;
		mlx->player.dir.x = mlx->player.dir.x * cos(-ROT_CONST) -
							mlx->player.dir.y * sin(-ROT_CONST);
		mlx->player.dir.y = mlx->player.lastdir.x * sin(-ROT_CONST) +
							mlx->player.dir.y * cos(-ROT_CONST);
		mlx->plane.oldx = mlx->plane.x;
		mlx->plane.oldy = mlx->plane.y;
		mlx->plane.x = mlx->plane.x * cos(-ROT_CONST) -
						mlx->plane.y * sin(-ROT_CONST);
		mlx->plane.y = mlx->plane.oldx * sin(-ROT_CONST) +
						mlx->plane.y * cos(-ROT_CONST);
	}
}
