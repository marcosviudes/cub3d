/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:28:41 by mviudes           #+#    #+#             */
/*   Updated: 2020/10/19 14:39:20 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	raycasting(t_mlx *mlx){
	int	i;

	i = 0;

	
}
int	press_key(int	key, t_mlx *mlx)
{
	if(key == KEY_W)
		mlx->move.forward = 1;
	if(key == KEY_S)
		mlx->move.backwards= 1;
	if(key == KEY_A)
		mlx->move.left = 1;
	if(key == KEY_D)
		mlx->move.right = 1;
	if(key == KEY_LEFT)
		mlx->move.rotleft = 1;
	if(key == KEY_RIGHT)
		mlx->move.rotright= 1;
	return(0);
}
int release_key(int key, t_mlx *mlx)
{
	if(key == KEY_W)
		mlx->move.forward = 0;
	if(key == KEY_S)
		mlx->move.backwards= 0;
	if(key == KEY_A)
		mlx->move.left = 0;
	if(key == KEY_D)
		mlx->move.right = 0;
	if(key == KEY_LEFT)
		mlx->move.rotleft = 0;
	if(key == KEY_RIGHT)
		mlx->move.rotright= 0;
	if(key == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}