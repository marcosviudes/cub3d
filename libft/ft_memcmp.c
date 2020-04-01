/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:53:22 by mviudes           #+#    #+#             */
/*   Updated: 2019/12/06 14:42:13 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*string1;
	const char	*string2;
	size_t		i;

	string1 = s1;
	string2 = s2;
	i = 0;
	while (i < n)
	{
		if (string1[i] != string2[i])
			return ((unsigned char)string1[i] - (unsigned char)string2[i]);
		i++;
	}
	return (0);
}
