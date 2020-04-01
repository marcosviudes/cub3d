/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:42:30 by mviudes           #+#    #+#             */
/*   Updated: 2019/11/26 17:59:13 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnlen(const char *s, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (len++ < maxlen)
		if (*s++ == '\0')
			break ;
	return (len - 1);
}
