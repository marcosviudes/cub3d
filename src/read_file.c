/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:21:05 by mviudes           #+#    #+#             */
/*   Updated: 2020/07/25 20:23:31 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>
#include <ft_utils.h>

int     read_line(t_config *config, char *line)
{
	int 	i;
    char 	**spline;

	i = 0;
	
	while (ft_iswhitespace(line[i]) == 1)
        i++;
	if(ft_isdigit(line[i]))
		return(read_map(config, line));
	spline = ft_split(line, ' ');
    if (ft_cmpstr(*spline, "R"))
		fillResolution(config, spline);
	else if(ft_cmpstr(*spline, "NO") || 
			ft_cmpstr(*spline, "SO") || 
			ft_cmpstr(*spline, "WE") || 
			ft_cmpstr(*spline, "EA") || 
			ft_cmpstr(*spline, "S"))
		fillTexture(config, spline);
	else if (ft_cmpstr(*spline, "F") || 
				ft_cmpstr(*spline, "C"))
		fillAmbient(config, spline);
	return 0;
}

int			fillResolution(t_config *config, char **spline)
{	
	int i;
	int	resolution[3];

	i = 1;
	if(config->resolutionflag == 1)
		return 0;
	while (i < 3)
	{
		if(!spline[i])
			resolution[i] = -1;
		else if(!ft_strisnum(spline[i]))
			resolution[i]= 0;
		else
			resolution[i] = atoi(spline[i]);
		i++;	
	}
	config->ResolutionWidht = resolution[1];
	config->ResolutionHeight = resolution[2];
	config->resolutionflag = 1;
	return 0;
}

void		checkResolution(t_config *config)
{	
	if (config->ResolutionWidht > MAX_WIDHT || config->ResolutionHeight > MAX_HEIGHT)
	{	
		config->ResolutionWidht = MAX_WIDHT;
		config->ResolutionHeight = MAX_HEIGHT;
	}
	if(!config->ResolutionHeight || !config->ResolutionWidht)
		printf("No se ha encontrado resolución\n");
	else if(config->ResolutionHeight == 0 && config->ResolutionWidht == 0)
		printf("Resolucion invalida\n");
	if(config->ResolutionHeight == -1 || config->ResolutionWidht == -1)
		printf("faltan numeros de resolucion\n");
}
int	fillAmbient(t_config *config, char **spline)
{
	int rgb[3];
	int i;
	char **numbers;

	i = 0;
	if (!spline)
		return (0);
	numbers = ft_split(spline[1], ',');
	while(i < 3)
	{
		rgb[i] = ft_atoi(numbers[i]);
		i++;
	}
	i = -1;
	if(*spline[0] == 'F' && config->floorflag == 0)
		{
			while(i++ < 3)
				config->floor[i] = rgb[i];
		}
	if(*spline[0] == 'C')
		{
			while(i++ < 3)
				config->ceiling[i] = rgb[i];
		}
	return 0;
}
int         fillTexture(t_config *config, char **spline)
{
	if (!spline[1])
		return (0);
	else if(ft_cmpstr(*spline, "NO") && config->texturenorthflag == 0)
	{
		config->tex_path_north = spline[1];
		config->texturenorthflag = 1;
	}
	else if (ft_cmpstr(*spline, "SO") && config->texturesouthflag == 0)
	{
		config->tex_path_south = spline[1];
		config->texturesouthflag = 1;
	}
	else if (ft_cmpstr(*spline, "WE") && config->texturewestflag == 0)
	{
		config->tex_path_west = spline[1];
		config->texturewestflag = 1;
	}
	else if (ft_cmpstr(*spline, "EA") && config->textureeastflag == 0)
	{
		config->tex_path_east = spline[1];
		config->textureeastflag = 1;
	}
	else if (ft_cmpstr(*spline, "S") && config->texturespriteflag == 0)
	{
		config->tex_sprite = spline[1];
		config->texturespriteflag = 1;
	}
	return (0);
}
int		read_map(t_config *config, char *line)
{
	
	config->map;
	return (0)	;
}