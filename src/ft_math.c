/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:44:51 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/20 11:59:08 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_math.h>
#include <math.h>

float	ft_torad(float degree)
{
	return (degree * (M_PI / 180.0));
}

float	ft_todeg(float radians)
{
	return (radians * (180.0 / M_PI));
}

int		ft_sign(int number)
{
	if (number < 0)
		return (-1);
	if (number > 0)
		return (1);
	return (0);
}
