/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 13:15:12 by mviudes           #+#    #+#             */
/*   Updated: 2020/08/05 13:36:00 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <read_map.h>
#include <ft_utils.h>

int		get_size_map(t_config *config, char *line)
{
	int i; 

	i = 1;
	config->map.max_height++;
	while (((line[i] >= 48 && line[i] <= 57) || line[i] == ' ' ||
			line[i] == 'N' || line[i] == 'S' || line[i] == 'W' ||
			line[i] == 'E') &&
			line[i])
		i++;
//	while (ft_strchr(VALID_CHAR_MAP, line[i]) && line[i])
//		i++;
	if (i > config->map.max_widht)
		config->map.max_widht = i;
	return 1;
}

int				read_map(t_config *config, char *line)
{
	config->flags.readingmap = 1;
	get_size_map(config, line);
	copy_map(config, line);
	if (config->lastline == 0)
	{
		allocate_map(config);
		fill_map(config);
	}
	return (0);
}



void		allocate_map(t_config  *config)
{
	int		i;

	i = 0;
	config->map.map = ft_calloc(sizeof(int*), config->map.max_height);
	while (i < config->map.max_height)
	{
		config->map.map[i] = ft_calloc(sizeof(int), config->map.max_widht);
		i++;
	}
}

void		get_init_position(t_config *config, int widht, int height)
{
	config->init_pos.x = widht;
	config->init_pos.y = height;
	config->flags.initpos += 1;
}

int			copy_map(t_config *config, char *line)
{
	t_lstbuff	*tmp;
	char 		*newstr;

	newstr = ft_strdup(line);
	tmp = ft_lstbuff_new(newstr);
	ft_lstbuffadd_back(&(config->map.buff),tmp);
	//free(tmp);
	return (0);
}

t_lstbuff	*ft_lstbuff_new(char const *content)
{
	t_lstbuff	*new;

	if (!(new = (t_lstbuff*)malloc(sizeof(content))))
		return (NULL);
	new->line = (char *)content;
	new->next = NULL;
	return (new);
}

void		ft_lstbuffadd_back(t_lstbuff **lst, t_lstbuff *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstbufflast(*lst)->next = new;
}

t_lstbuff	*ft_lstbufflast(t_lstbuff *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int			fill_map(t_config *config)
{
	int		row;
	int		column;
	char	*line;
	int		i;

	row = 0;
	line = 0;
	while(config->map.max_height > row)
	{
		while(lst)
		config->map.map[row][column];
		row++;
		i++;
	}
	return(0)
}

char		*ft_lstpop_first(t_lstbuff *lst)
{
	
}