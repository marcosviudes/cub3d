/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:42:41 by mviudes           #+#    #+#             */
/*   Updated: 2019/12/06 21:05:15 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(content))))
		return (NULL);
	new->content = (void *)content;
	new->next = NULL;
	return (new);
}
