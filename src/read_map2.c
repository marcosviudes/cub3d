/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:54:22 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/22 10:35:51 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <read_map.h>
#include <ft_utils.h>

void				fill_map_sub(t_config *config, int row, int i, char c)
{
	if (ft_iswhitespace(c))
		config->map.map[row][i] = 4;
	else if (ft_isdigit(c))
		config->map.map[row][i] = c - '0';
	else if (ft_isascii(c))
	{
		config->init_dir = c;
		get_init_position(config, i, row);
		config->map.map[row][i] = 0;
	}
	else
		config->map.map[row][i] = 4;
}
