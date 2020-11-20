/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:53:24 by mviudes           #+#    #+#             */
/*   Updated: 2020/11/02 12:45:34 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_UTILS_H
# define DRAW_UTILS_H


void	draw_square(void *mlx, void *win, int posx, int posy, int size, int color);
void	draw_player(t_mlx *mlx, t_player *player);
void    draw_line(t_mlx *mlx, void *win,int x1, int y1, int x2, int y2,int color);


void drawline_lendown(t_mlx *mlx, int posx, int posy, int len);
#endif