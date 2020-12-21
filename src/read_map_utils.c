/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:49:11 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 17:52:24 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <read_map.h>
#include <ft_utils.h>

int					get_size_map(t_config *config, char *line)
{
	int				i;

	i = 1;
	config->map.max_height++;
	while (((line[i] >= 48 && line[i] <= 57) || line[i] == ' ' ||
			line[i] == 'N' || line[i] == 'S' || line[i] == 'W' ||
			line[i] == 'E') &&
			line[i])
		i++;
	if (i > config->map.max_width)
		config->map.max_width = i;
	return (1);
}

void				allocate_map(t_config *config)
{
	int				i;

	i = 0;
	config->map.map = ft_calloc(sizeof(int*), config->map.max_height);
	while (i < config->map.max_height)
	{
		config->map.map[i] = ft_calloc(sizeof(int), config->map.max_width);
		i++;
	}
}

void				get_init_position(t_config *config, int width, int height)
{
	config->init_pos.x = height;
	config->init_pos.y = width;
	config->flags.initpos += 1;
}

int					copy_map(t_config *config, char *line)
{
	t_lstbuff		*tmp;
	char			*newstr;

	newstr = ft_strdup(line);
	tmp = ft_lstbuff_new(newstr);
	ft_lstbuffadd_back(&(config->map.buff), tmp);
	return (0);
}

int					map_fill_with(t_config *config, char c)
{
	int				j;
	int				i;

	j = 0;
	while (j < config->map.max_height)
	{
		i = 0;
		while (i < config->map.max_width)
		{
			config->map.map[j][i] = c - '0';
			i++;
		}
		j++;
	}
	return (0);
}
