/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:53:24 by mviudes           #+#    #+#             */
/*   Updated: 2020/08/17 10:22:48 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_UTILS_H
# define DRAW_UTILS_H


void	draw_square(void *mlx, void *win, int posx, int posy, int size, int color);
void	draw_player(float posx, float posy, float dir);
#endif