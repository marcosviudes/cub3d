/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:29:25 by mviudes           #+#    #+#             */
/*   Updated: 2019/11/16 22:39:59 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	int	*ptr;

	ptr = malloc(num * size);
	if (!(ptr))
		return (0);
	return (ft_memset(ptr, 0, (num * size)));
}
