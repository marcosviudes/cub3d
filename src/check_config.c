/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:10:15 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 18:50:49 by mviudes          ###   ########.fr       */
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
	if (config->resolutionwidth == 0 || config->resolutionheight == 0)
		error_exit("Invalid Resolution");
	if (config->resolutionwidth == -1 || config->resolutionheight == -1)
		error_exit("Missed resolution Numbers");
	if (config->resolutionwidth > MAX_WIDTH
		|| config->resolutionheight > MAX_HEIGHT)
	{
		config->resolutionwidth = MAX_WIDTH;
		config->resolutionheight = MAX_HEIGHT;
	}
	if (config->resolutionwidth <= MIN_RES
		|| config->resolutionheight <= MIN_RES)
	{
		config->resolutionwidth = MIN_RES;
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
		if (config->floorcolor[i] > MAX_COLOR_RNG)
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
		if (config->ceilingcolor[i] > MAX_COLOR_RNG)
			error_exit("Ceil colors shouldn't be graer than 255");
		i++;
	}
	return (0);
}

void		check_direction(t_config *config)
{
	char c;

	c = '\0';
	c = config->init_dir;
	if (config->flags.initpos == 0)
		error_exit("Player not found");
	if (config->flags.initpos > 1)
		error_exit("Found more than one player");
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && c != '\0')
		return ;
	error_exit("Invalid direction");
}

void		check_extension(char *path, char *ext)
{
	char	*ptr_ext;
	int		extlen;

	ptr_ext = NULL;
	if (!path || !ext)
		return ;
	while (*path != '\0')
	{
		if (*path == ext[0])
			ptr_ext = path;
		path++;
	}
	extlen = ft_strlen(ext);
	if (ptr_ext != NULL && ft_strncmp(ptr_ext, ext, extlen + 1) == 0)
		return ;
	error_exit("Not valid extension");
}
