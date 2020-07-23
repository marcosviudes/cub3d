/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:21:05 by mviudes           #+#    #+#             */
/*   Updated: 2020/07/23 22:01:58 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>
#include <ft_utils.h>

/*int     check_resolution(t_config config, char *line)
{
        return 0;
}*/
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
    if(ft_cmpstr(*spline, "R"))
		{
			config->ResolutionWidht = atoi(spline[1]);
			config->ResolutionHeight = atoi(spline[2]);
		}
    else if(ft_cmpstr(*spline, "NO"))
		config->tex_path_north = spline[1];
    else if (ft_cmpstr(*spline, "SO"))
		config->tex_path_south = spline[1];
	else if (ft_cmpstr(*spline, "WE"))
		config->tex_path_west = spline[1];
	else if (ft_cmpstr(*spline, "EA"))
		config->tex_path_east = spline[1];
	else if (ft_cmpstr(*spline, "S"))
		config->tex_sprite = spline[1];
	else if (ft_cmpstr(*spline, "F"))
		config->floor = spline[1];
	else if (ft_cmpstr(*spline, "C"))
		config->ceiling = spline[1];
	return 0;
}
int		read_map(t_config *config, char *line)
{
	return (0)	;
}/*
int		ft_cmpstr(char* string1, char* string2)
{
	int i;

	i = 0;
	if(string1 && string2)
	{
		while(string1[i] != '\0' || string2[i] != '\0')
		{
			if(string1[i] != string2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}*/
/*

	
	


int     check_resolution(t_config *config, char line)
{
        printf("hola");
}*/