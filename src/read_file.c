/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:21:05 by mviudes           #+#    #+#             */
/*   Updated: 2020/07/23 13:29:08 by mviudes          ###   ########.fr       */
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
    char 	**ret;

	i = 0;
	
	while (ft_iswhitespace(line[i]) == 1)
        i++;
	if(ft_isdigit(line[i]))
		return(read_map(config, line));
	ret = ft_split(line, ' ');
    if(ft_cmpstr(ret[0], "R"))
		{
			config->ResolutionWidht = atoi(ret[1]);
			config->ResolutionHeight = atoi(ret[2]);
		}
    else if(ft_cmpstr(ret[0], "NO"))
		config->tex_path_north = (ret[1]);
    else if (ft_cmpstr(ret[0], "SO"))
		config->tex_path_south = (ret[1]);
	else if (ft_cmpstr(ret[0], "WE"))
		config->tex_path_west = (ret[1]);
	else if (ft_cmpstr(ret[0], "EA"))
		config->tex_path_east = (ret[1]);
	else if (ft_cmpstr(ret[0], "S"))
		config->tex_sprite = (ret[1]);
	else if (ft_cmpstr(ret[0], "F"))
		config->floor = (ret[1]);
	else if (ft_cmpstr(ret[0], "C"))
		config->ceiling = (ret[1]);
	return 0;
}
int		read_map(t_config *config, char *line)
{
	return (0)	;
}
int		ft_cmpstr(char* string1, char* string2)
{
	int i;

	i = 0;
	if(string1 && string2)
	{
	while(string1[i] != '\0' && string2[i] != '\0')
	{
		if(string1[i] != string2[i])
			return (0);
		i++;
	}
	return (1);
	}
	return (-1);
}
/*

	
	


int     check_resolution(t_config *config, char line)
{
        printf("hola");
}*/