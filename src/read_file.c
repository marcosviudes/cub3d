/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:21:05 by mviudes           #+#    #+#             */
/*   Updated: 2020/07/22 15:29:42 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>
#include <ft_utils.h>

/*int     check_resolution(t_config config, char *line)
{
        return 0;
}*/
int			read_line(t_config *config, char *line)
{
	int		i;
	char	**line_info;
	int l = 0;
	i = 0;
    while (ft_iswhitespace(line[i]) == 1)
        i++;
	line_info = ft_getsubstrings(line);
	while(line_info[l] != NULL)
		printf("line_info[%i] vale:%s", l, line_info[l]);
 /*   if(*line == 'R')
        check_resolution(config, *line);
*/
    return 0;
}
/*
int     check_resolution(t_config *config, char line)
{
        printf("hola");
}*/