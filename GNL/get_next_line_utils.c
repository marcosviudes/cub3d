/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:09:51 by mviudes           #+#    #+#             */
/*   Updated: 2020/07/20 11:17:35 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <libft.h>
#include <cub3d.h>

char			*ft_strchr(const char *str, int c)
{
	int			i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)str + ft_strlen((char *)str));
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char			*ft_strcdup(const char *src, int c)
{
	int			i;
	int			j;
	char		*s2;

	i = 0;
	j = 0;
	while (src[i] && src[i] != c)
		i++;
	s2 = malloc((i + 1) * sizeof(char));
	if (!(s2))
		return (0);
	while (j < i)
	{
		s2[j] = src[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

size_t			ft_strnlen(const char *s, size_t maxlen)
{
	size_t		len;

	len = 0;
	while (len++ < maxlen)
		if (*s++ == '\0')
			break ;
	return (len - 1);
}
