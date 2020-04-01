/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:15:23 by mviudes           #+#    #+#             */
/*   Updated: 2019/12/07 09:42:18 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void		*ft_memchr(const void *str, int c, size_t n)
{
	char	*string;
	char	caracter;
	size_t	i;

	i = 0;
	string = (char *)str;
	caracter = (char)c;
	while (i < n)
	{
		if (string[i] == caracter)
			return (&string[i]);
		i++;
	}
	return (0);
}
