/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:10:15 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/19 11:20:04 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <read_map.h>
#include <ft_utils.h>

void		check_resolution(t_config *config)
{
	if (config->flags.resolution > 1)
		error_exit("Found more than one resolution.");
	if (config->flags.resolution <= 0)
		error_exit("Resolution not found.");
	if (config->resolutionwidht == 0 || config->resolutionheight == 0)
		error_exit("Invalid Resolution");
	if (config->resolutionwidht == -1 || config->resolutionheight == -1)
		error_exit("Missed resolution Numbers");
	if (config->resolutionwidht > MAX_WIDHT
		|| config->resolutionheight > MAX_HEIGHT)
	{
		config->resolutionwidht = MAX_WIDHT;
		config->resolutionheight = MAX_HEIGHT;
	}
	if (config->resolutionwidht <= MIN_RES
		|| config->resolutionheight <= MIN_RES)
	{
		config->resolutionwidht = MIN_RES;
		config->resolutionheight = MIN_RES;
	}
}

int			check_floor(t_config *config)
{
	int		i;

	i = 0;
	if (config->flags.floor > 1)
		error_exit("Found more than one Floor color");
	if (config->flags.floor <= 0)
		error_exit("Floor color not Found");
	while (i < 3)
	{
		if (config->floorcolor[i] < 0)
			error_exit("Floor colors should be grater than 0");
		if (config->floorcolor[i] > MAX_COLOR_RANGE)
			error_exit("Floor colors shouldn't be graer than 255");
		i++;
	}
	return (0);
}

int			check_ceiling(t_config *config)
{
	int		i;

	i = 0;
	if (config->flags.cealing > 1)
		error_exit("Found more than one Ceil color");
	if (config->flags.cealing <= 0)
		error_exit("Ceil color not Found");
	while (i < 3)
	{
		if (config->ceilingcolor[i] < 0)
			error_exit("Ceil colors should be grater than 0");
		if (config->ceilingcolor[i] > MAX_COLOR_RANGE)
			error_exit("Ceil colors shouldn't be graer than 255");
		i++;
	}
	return (0);
}

int			check_textures_north(t_config *config)
{
	if (config->flags.texturenorth > 1)
		error_exit("more than one NO texture");
	else if (config->flags.texturenorth <= 0)
		error_exit("NO texture not fund");
	else if (config->flags.texturenorth == 1 && !config->tex_path_north)
		error_exit ("Invalid NO texture");
	else if (!config->tex_path_north)
		error_exit ("Introduce a NO texture");
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
		error_exit ("Invalid SO texture");
	else if (!config->tex_path_south)
		error_exit ("Introduce a SO texture");
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
		error_exit ("Invalid W texture");
	else if (!config->tex_path_west)
		error_exit ("Introduce a W texture");
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
		error_exit ("Textura EA invalida");
	else if (!config->tex_path_east)
		error_exit ("Introduce a EA texture");
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
		error_exit ("Textura s invalida");
	else if (!config->tex_sprite)
		error_exit ("Introduce a s texture");
	check_extension(config->tex_sprite, TEX_EXT);
	return (1);
}
void		check_textures(t_config *config)
{
	check_textures_north(config);
	check_textures_south(config);
	check_textures_west(config);
	check_textures_east(config);
	check_textures_sprite(config);
}
void		check_direction(t_config *config)
{
	char c;

	c = '\0';
	c = config->init_dir;
	if(config->flags.initpos == 0)
		error_exit("Player not found");
	if(config->flags.initpos > 1)
		error_exit("Found more than one player");
	if((c == 'N' || c == 'S' || c == 'W' || c == 'E') && c != '\0')
		return;	
	error_exit("Invalid direction");
}

void		check_extension(char *path, char *ext){
	char *ptr_ext;
	int extlen;

	ptr_ext = NULL;
	if(!path || !ext)
		return;
	while(*path != '\0')
		{
			if(*path == ext[0])
				ptr_ext = path;
			path++;
		}
	extlen = ft_strlen(ext);
	if(ptr_ext != NULL && ft_strncmp(ptr_ext, ext, extlen +1) == 0)
		return;
	error_exit("Not valid extension");
}
void		free_map(t_map map){
	return; 
}