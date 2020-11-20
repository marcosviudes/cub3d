/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:42:01 by mviudes           #+#    #+#             */
/*   Updated: 2020/11/02 11:22:20 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_MATH_H
 #define _FT_MATH_H
# include <cub3d.h>

#define DEG_RAD 0.0174533

float	ft_torad(float degrees);
float	ft_todeg(float radians);
int 	ft_sign(int number);
#endif