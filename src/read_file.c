/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:21:05 by mviudes           #+#    #+#             */
/*   Updated: 2020/07/27 13:14:12 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>
#include <ft_utils.h>

int				fill_resolution(t_config *config, char **spline)
{
	int 		i;
	int			resolution[3];

	i = 1;
	while (i < 3)
	{
		if (!spline[i])
			resolution[i] = -1;
		else if (!ft_strisnum(spline[i]))
			resolution[i] = 0;
		else
			resolution[i] = atoi(spline[i]);
		i++;
	}
	config->resolutionwidht = resolution[1];
	config->resolutionheight = resolution[2];
	config->flags.resolution += 1;
	return (0);
}

int				fill_ambientcolor(t_config *config, char **spline)
{
	int		rgb[3];
	int		i;
	char	**numbers;

	i = 0;
	numbers = ft_split(spline[1], ',');
	while (i < 3)
	{
		rgb[i] = ft_atoi(numbers[i]);
		i++;
	}
	i = -1;
	if (*spline[0] == 'F')
	{
		while (i++ < 3)
			config->floorcolor[i] = rgb[i];
		config->flags.floor += 1;
	}
	if (*spline[0] == 'C')
	{
		while (i++ < 3)
			config->ceilingcolor[i] = rgb[i];
		config->flags.cealing += 1;
	}
	return (0);
}

void			fill_texture(t_config *config, char **spline)
{
	if (ft_cmpstr(*spline, "NO"))
	{
		config->tex_path_north = spline[1];
		config->flags.texturenorth += 1;
	}
	else if (ft_cmpstr(*spline, "SO"))
	{
		config->tex_path_south = spline[1];
		config->flags.texturesouth += 1;
	}
	else if (ft_cmpstr(*spline, "WE"))
	{
		config->tex_path_west = spline[1];
		config->flags.texturewest += 1;
	}
	else if (ft_cmpstr(*spline, "EA"))
	{
		config->tex_path_east = spline[1];
		config->flags.textureeast += 1;
	}
	else if (ft_cmpstr(*spline, "S"))
	{
		config->tex_sprite = spline[1];
		config->flags.texturesprite += 1;
	}
}

int				read_map(t_config *config, char *line)
{
	return (0)	;
}

int				read_line(t_config *config, char *line)
{
	int		i;
	char	**spline;

	i = 0;
	while (ft_iswhitespace(line[i]) == 1)
		i++;
	if (ft_isdigit(line[i]))
		return (read_map(config, line));
	spline = ft_split(line, ' ');
	if (*spline == NULL)
		return (0);
	if (ft_cmpstr(*spline, "R"))
		fill_resolution(config, spline);
	else if (ft_cmpstr(*spline, "NO") ||
			ft_cmpstr(*spline, "SO") ||
			ft_cmpstr(*spline, "WE") ||
			ft_cmpstr(*spline, "EA") ||
			ft_cmpstr(*spline, "S"))
		fill_texture(config, spline);
	else if (ft_cmpstr(*spline, "F") ||
				ft_cmpstr(*spline, "C"))
		fill_ambientcolor(config, spline);
	return (0);
}
