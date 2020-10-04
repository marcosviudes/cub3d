/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rraycasting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:28:41 by mviudes           #+#    #+#             */
/*   Updated: 2020/08/20 12:47:29 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	release_key(int	key, t_mlx *mlx)
{
	if(key == KEY_W)
		mlx->move.forward = 0;
	return(0);
}
int deal_key(int key, t_mlx *mlx)
{
	if(key == KEY_W)
		mlx->move.forward = 1;
	if(key == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}