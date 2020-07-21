/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:21:05 by mviudes           #+#    #+#             */
/*   Updated: 2020/07/17 13:38:28 by mviudes          ###   ########.fr       */
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
    while (ft_iswhitespace(*line) == 1)
        line++;
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