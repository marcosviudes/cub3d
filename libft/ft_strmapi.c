/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:43:06 by mviudes           #+#    #+#             */
/*   Updated: 2019/11/29 11:33:26 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	int		i;

	if (s != NULL)
	{
		string = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (string == NULL)
			return (NULL);
		i = 0;
		while (s[i])
		{
			string[i] = f(i, s[i]);
			i++;
		}
		string[ft_strlen(s)] = '\0';
		return (string);
	}
	return (0);
}
