/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:21:05 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 18:30:14 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>
#include <ft_utils.h>
#include <read_map.h>

int				fill_resolution(t_config *config, char **spline)
{
	int			i;
	int			resolution[3];

	i = 1;
	config->flags.resolution += 1;
	if (spline[3] != NULL)
		return (1);
	while (i < 3)
	{
		if (!spline[i])
			resolution[i] = -1;
		else if (!ft_strisnum(spline[i]))
			resolution[i] = 0;
		else if (ft_strlen(spline[i]) > 5)
			resolution[i] = 10000;
		else
			resolution[i] = ft_atoi(spline[i]);
		i++;
	}
	config->resolutionwidth = resolution[1];
	config->resolutionheight = resolution[2];
	return (0);
}

void			fill_texture(t_config *config, char **spline, int key)
{
	char		*texture;

	if (spline[2] != NULL)
	{
		if (key == K_NO)
			config->flags.texturenorth += 1;
		if (key == K_SO)
			config->flags.texturesouth += 1;
		if (key == K_WE)
			config->flags.texturewest += 1;
		if (key == K_EA)
			config->flags.textureeast += 1;
		if (key == K_S)
			config->flags.texturesprite += 1;
		return ;
	}
	texture = ft_strdup(spline[1]);
	while (ft_iswhitespace(*texture))
		texture++;
	fill_texture2(config, key, texture);
}

void			fill_texture2(t_config *config, int key, char *texture)
{
	if (key == K_NO)
	{
		config->tex_path_north = texture;
		config->flags.texturenorth += 1;
	}
	else if (key == K_SO)
	{
		config->tex_path_south = texture;
		config->flags.texturesouth += 1;
	}
	else if (key == K_WE)
	{
		config->tex_path_west = texture;
		config->flags.texturewest += 1;
	}
	else if (key == K_EA)
	{
		config->tex_path_east = texture;
		config->flags.textureeast += 1;
	}
	else if (key == K_S)
	{
		config->tex_sprite = texture;
		config->flags.texturesprite += 1;
	}
}

int				is_allwhitespace(char *line)
{
	int			i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_iswhitespace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int				select_ambient(t_config *config, char *line, int key)
{
	int			i;

	i = 0;
	if (key == K_F)
	{
		config->flags.floor += 1;
		fill_ambientcolor(config->floorcolor, line);
	}
	else if (key == K_C)
	{
		config->flags.cealing += 1;
		fill_ambientcolor(config->ceilingcolor, line);
	}
	return (0);
}
