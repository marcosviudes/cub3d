/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:51:18 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 17:51:29 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <read_map.h>
#include <ft_utils.h>

t_lstbuff			*ft_lstbuff_new(char const *content)
{
	t_lstbuff		*new;

	if (!(new = (t_lstbuff*)malloc(sizeof(content))))
		return (NULL);
	new->line = (char *)content;
	new->next = NULL;
	return (new);
}

void				ft_lstbuffadd_back(t_lstbuff **lst, t_lstbuff *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstbufflast(*lst)->next = new;
}

t_lstbuff			*ft_lstbufflast(t_lstbuff *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

char				*ft_lstpop_first(t_lstbuff **lst)
{
	char			*string;
	t_lstbuff		*next;

	next = NULL;
	if (*lst == NULL)
		return (NULL);
	next = (*lst)->next;
	string = (*lst)->line;
	free(*lst);
	*lst = next;
	return (string);
}
