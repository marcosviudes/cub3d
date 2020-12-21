/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 13:15:12 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 20:55:02 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <read_map.h>
#include <ft_utils.h>

int					read_map(t_config *config, char *line)
{
	config->flags.readingmap = 1;
	get_size_map(config, line);
	copy_map(config, line);
	if (config->lastline == 0)
	{
		allocate_map(config);
		fill_map(config);
		get_sprites(config);
	}
	return (0);
}

int					fill_map(t_config *config)
{
	int				row;
	char			*temp;
	int				i;
	int				j;

	row = 0;
	temp = 0;
	map_fill_with(config, '4');
	while (row < config->map.max_height)
	{
		temp = ft_lstpop_first(&config->map.buff);
		i = 0;
		while (temp[i] != '\0')
		{
			fill_map_sub(config, row, i, temp[i]);
			i++;
		}
		j++;
		row++;
		free(temp);
		temp = NULL;
	}
	return (0);
}

void				check_map_fours(t_config *config, int i, int j)
{
	if (config->map.map[j + 1][i] == 4)
		error_exit("mapa abierto");
	if (config->map.map[j][i + 1] == 4)
		error_exit("mapa abierto");
	if (config->map.map[j - 1][i] == 4)
		error_exit("mapa abierto");
	if (config->map.map[j][i - 1] == 4)
		error_exit("mapa abierto");
}

void				check_map_walls(t_config *config)
{
	int				i;
	int				j;
	int				temp;

	i = 1;
	j = 1;
	while (j < config->map.max_height - 1)
	{
		i = 0;
		while (i < config->map.max_width - 1)
		{
			if (config->map.map[j][i] < 0 || config->map.map[j][i] > 4)
				error_exit("Invalid map");
			if (config->map.map[j][i] == 0 ||
				config->map.map[j][i] == 2)
				check_map_fours(config, i, j);
			i++;
		}
		j++;
	}
	check_map_walls2(config);
}

void				check_map_walls2(t_config *config)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < config->map.max_width - 1)
	{
		if (config->map.map[0][i] != 1)
			if (config->map.map[0][i] != 4)
				error_exit("mapa abierto");
		if (config->map.map[config->map.max_height - 1][i] != 1)
			if (config->map.map[config->map.max_height - 1][i] != 4)
				error_exit("mapa abierto");
		i++;
	}
	while (j < config->map.max_height - 1)
	{
		if (config->map.map[j][0] != 1)
			if (config->map.map[j][0] != 4)
				error_exit("mapa abierto");
		if (config->map.map[j][config->map.max_width - 1] != 1)
			if (config->map.map[j][config->map.max_width - 1] != 4)
				error_exit("mapa abierto");
		j++;
	}
}
