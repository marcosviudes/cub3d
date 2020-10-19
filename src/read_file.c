/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:21:05 by mviudes           #+#    #+#             */
/*   Updated: 2020/10/08 11:56:45 by mviudes          ###   ########.fr       */
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
	if (spline[3] != NULL)
		return (1);
	while (i < 3)
	{
		if (!spline[i])
			resolution[i] = -1;
		else if (!ft_strisnum(spline[i]))
			resolution[i] = 0;
		else
			resolution[i] = ft_atoi(spline[i]);
		i++;
	}
	i = 0;
	config->resolutionwidht = resolution[1];
	config->resolutionheight = resolution[2];
	config->flags.resolution += 1;
	return (0);
}

void			fill_texture(t_config *config, char **spline, int key)
{
	if (key == K_NO)
	{
		config->tex_path_north = ft_strdup(spline[1]);
		config->flags.texturenorth += 1;
	}
	else if (key == K_SO)
	{
		config->tex_path_south = ft_strdup(spline[1]);
		config->flags.texturesouth += 1;
	}
	else if (key == K_WE)
	{
		config->tex_path_west = ft_strdup(spline[1]);
		config->flags.texturewest += 1;
	}
	else if (key == K_EA)
	{
		config->tex_path_east = ft_strdup(spline[1]);
		config->flags.textureeast += 1;
	}
	else if (key == K_S)
	{
		config->tex_sprite = ft_strdup(spline[1]);
		config->flags.texturesprite += 1;
	}
}



int				read_line(t_config *config, char *line)
{
	int		i;
	char	**spline;
	int		key;

	i = 0;
	if(!(spline = ft_split(line, ' ')) || line[0] == '\0'){
		free(spline);
		return(0);
	}
	key = get_key(spline[0]);
	while (ft_iswhitespace(line[i]))
		i++;
	if (ft_isdigit(line[i]))
		read_map(config, line);
	if (key == K_R)
		fill_resolution(config, spline);
	else if (key >= K_NO && key <= K_S)
		fill_texture(config, spline, key);
	else if (key == K_F || key == K_C)
		select_ambient(config, line, spline, key);
	i = 0;
	while(spline[i]){
		free(spline[i]);
		i++;
	}
	free(spline);
	line = NULL;
	return (0);
}


int				select_ambient(t_config *config, char *line, char **spline, int key)
{
	int i;

	i = 0;
	if (key == K_F)
	{
		config->flags.floor += 1;
		fill_ambientcolor(config->floorcolor, spline);
	}
	else if (key == K_C)
	{
		config->flags.cealing += 1;
		fill_ambientcolor(config->ceilingcolor, spline);
	}
		return (0);
}

int				fill_ambientcolor(int *color, char **spline)
{
	int			rgb[3];
	int			i;
	char		**numbers;

	i = 0;
//	ft_remchar(spline[1], ' ');
	numbers = ft_split(spline[1], ',');
	while (i < 3)
	{
		rgb[i] = ft_atoi(numbers[i]);
		free(numbers[i]);
		i++;
	}
	i = -1;
	while (i++ < 3)
		color[i] = rgb[i];
	free(numbers);
	return (0);
}