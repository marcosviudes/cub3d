/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 13:15:12 by mviudes           #+#    #+#             */
/*   Updated: 2020/08/03 12:34:01 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <read_map.h>

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
	if (i > config->map.max_widht)
		config->map.max_widht = i;
	return 1;
}

int				read_map(t_config *config, char *line)
{
	config->flags.readingmap = 1;
	get_size_map(config, line);
	if (config->lastline == 0)
	{
		allocate_map(config);
	}
	return (0);
}

int				copy_map(t_config *config, char *line)
{
	static char	*buff;
	char		*temp;
	char		*temp2;

	if (buff == NULL)
		buff = ft_strdup("");
	temp = ft_strjoin(buff, line);
	temp2 = ft_strjoin(temp, "\n");
	free(temp);
	free(buff);
	buff = temp2;
	return (0);
}

void		get_init_position(t_config *config, int widht, int height)
{
	config->init_pos.x = widht;
	config->init_pos.y = height;
	config->flags.initpos += 1;
}

void		allocate_map(t_config  *config)
{
	int		i;

	i = 0;
	config->map.map = ft_calloc(sizeof(int*), config->map.max_height);
	while(i < config->map.max_height)
	{
		config->map.map[i] = ft_calloc(sizeof(int), config->map.max_widht);
		i++;
	}
}