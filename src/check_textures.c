/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:49:56 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 18:51:38 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <read_map.h>
#include <ft_utils.h>

void		check_textures(t_config *config)
{
	check_textures_north(config);
	check_textures_south(config);
	check_textures_west(config);
	check_textures_east(config);
	check_textures_sprite(config);
}
