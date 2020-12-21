/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:17:59 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 18:23:06 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_charcount(char *string, int c)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (string[i] != '\0')
	{
		if (string[i] == c)
			count++;
		i++;
	}
	return (count);
}
