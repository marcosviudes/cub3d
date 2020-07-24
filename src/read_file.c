/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:21:05 by mviudes           #+#    #+#             */
/*   Updated: 2020/07/24 13:04:57 by mviudes          ###   ########.fr       */
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
		fillResolution(config, spline);
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
}

int			fillResolution(t_config *config, char **spline)
{	
	if(!spline[1])
		config->ResolutionWidht = -1;
	else
		config->ResolutionWidht = atoi(spline[1]);
	if(!spline[2])
		config->ResolutionHeight = -1;
	else
		config->ResolutionHeight = atoi(spline[2]);
	if (config->ResolutionWidht > 2880 || config->ResolutionHeight > 1395)
	{	
		config->ResolutionWidht = 2880;
		config->ResolutionHeight = 1395;
	}

		return (0);
}
void		checkResolution(t_config *config)
{
	if(!config->ResolutionHeight || !config->ResolutionWidht)
		printf("No se ha encontrado resolución\n");
	else if(config->ResolutionHeight == 0 && config->ResolutionWidht == 0)
		printf("Resolucion invalida\n");
	if(config->ResolutionHeight == -1 || config->ResolutionWidht == -1)
		printf("faltan numeros de resolucion\n");
}
