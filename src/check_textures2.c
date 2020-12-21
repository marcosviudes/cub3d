/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:48:35 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 18:49:10 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <read_map.h>
#include <ft_utils.h>

int			check_textures_north(t_config *config)
{
	if (config->flags.texturenorth > 1)
		error_exit("more than one NO texture");
	else if (config->flags.texturenorth <= 0)
		error_exit("NO texture not fund");
	else if (config->flags.texturenorth == 1 && !config->tex_path_north)
		error_exit("Invalid NO texture");
	else if (!config->tex_path_north)
		error_exit("Introduce a NO texture");
	check_extension(config->tex_path_north, TEX_EXT);
	return (1);
}

int			check_textures_south(t_config *config)
{
	if (config->flags.texturesouth > 1)
		error_exit("more than one SO texture");
	else if (config->flags.texturesouth <= 0)
		error_exit("SO texture not fund");
	else if (config->flags.texturesouth == 1 && !config->tex_path_south)
		error_exit("Invalid SO texture");
	else if (!config->tex_path_south)
		error_exit("Introduce a SO texture");
	check_extension(config->tex_path_south, TEX_EXT);
	return (1);
}

int			check_textures_west(t_config *config)
{
	if (config->flags.texturewest > 1)
		error_exit("More than one W texture");
	else if (config->flags.texturewest <= 0)
		error_exit("W texture not fund");
	else if (config->flags.texturewest == 1 && !config->tex_path_west)
		error_exit("Invalid W texture");
	else if (!config->tex_path_west)
		error_exit("Introduce a W texture");
	check_extension(config->tex_path_west, TEX_EXT);
	return (1);
}

int			check_textures_east(t_config *config)
{
	if (config->flags.textureeast > 1)
		error_exit("More than one EA texture");
	else if (config->flags.textureeast <= 0)
		error_exit("EA texture not fund");
	else if (config->flags.textureeast == 1 && !config->tex_path_east)
		error_exit("Textura EA invalida");
	else if (!config->tex_path_east)
		error_exit("Introduce a EA texture");
	check_extension(config->tex_path_east, TEX_EXT);
	return (1);
}

int			check_textures_sprite(t_config *config)
{
	if (config->flags.texturesprite > 1)
		error_exit("More than one S texture");
	else if (config->flags.texturesprite <= 0)
		error_exit("S texture not fund");
	else if (config->flags.texturesprite == 1 && !config->tex_sprite)
		error_exit("Textura s invalida");
	else if (!config->tex_sprite)
		error_exit("Introduce a s texture");
	check_extension(config->tex_sprite, TEX_EXT);
	return (1);
}
