/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 11:15:01 by mviudes           #+#    #+#             */
/*   Updated: 2020/08/03 13:15:58 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _READ_MAP_H_
# define _READ_MAP_H_
#include <cub3d.h>

int					read_map(t_config *config, char	*line);
int					copy_map(t_config *config, char *line);
int					get_size_map(t_config *config, char *line);
void				allocate_map(t_config *config);
void				fill_map(t_config *config);
#endif