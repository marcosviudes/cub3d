/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:53:02 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 17:58:52 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <read_map.h>
#include <ft_utils.h>

void				get_sprites(t_config *config)
{
	countmap_sprites(config);
	free(config->sprite);
	if (!(config->sprite = (t_sprite*)malloc(sizeof(t_sprite)
							* config->spritecount - 1)))
		return ;
	save_sprites(config);
}

void				countmap_sprites(t_config *config)
{
	int				j;
	int				i;

	i = 0;
	j = 0;
	while (j < config->map.max_height)
	{
		i = 0;
		while (i < config->map.max_width)
		{
			if (config->map.map[j][i] == 2)
				config->spritecount++;
			i++;
		}
		j++;
	}
}

void				save_sprites(t_config *config)
{
	int				i;
	int				j;
	int				k;

	k = 0;
	j = 0;
	i = 0;
	while (j < config->map.max_height)
	{
		i = 0;
		while (i < config->map.max_width)
		{
			if (config->map.map[j][i] == 2 && k < config->spritecount)
			{
				config->sprite[k].x = j + 0.5;
				config->sprite[k].y = i + 0.5;
				config->sprite[k].id = k;
				k++;
			}
			i++;
		}
		j++;
	}
}
