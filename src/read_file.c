/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:21:05 by mviudes           #+#    #+#             */
/*   Updated: 2020/07/07 22:55:11 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>

/*int     check_resolution(t_config config, char *line)
{
        return 0;
}*/
int     read_line(t_config *config, char *line)
{
    while (ft_iswhitespace(*line))
        line++;
    if(*line == 'R')
        check_resolution(config, *line);

    return 0;
}
int     check_resolution(t_config *config, char line)
{
        printf("hola");
}