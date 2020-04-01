/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:43:35 by mviudes           #+#    #+#             */
/*   Updated: 2019/11/15 19:50:41 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*destination;
	unsigned const char	*source;
	size_t				i;

	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		if (source[i] == (unsigned char)c)
		{
			i++;
			return ((unsigned char *)&destination[i]);
		}
		i++;
	}
	return (0);
}
