/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:30:05 by mviudes           #+#    #+#             */
/*   Updated: 2019/12/07 09:51:06 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t				i;
	size_t				j;
	unsigned const char	*s1;
	unsigned const char	*s2;

	i = 0;
	s1 = (unsigned const char*)haystack;
	s2 = (unsigned const char*)needle;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if ((i + j + 1) > len)
				return (0);
			if (s2[j + 1] == '\0')
				return ((char*)s1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
