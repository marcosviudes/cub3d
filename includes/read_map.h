/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 11:15:01 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 14:19:57 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H
# include <cub3d.h>

# define K_R	1
# define K_NO	2
# define K_SO	3
# define K_WE	4
# define K_EA	5
# define K_S	6
# define K_F	7
# define K_C	8
# define K_MAP	9

int					read_map(t_config *config, char	*line);
int					copy_map(t_config *config, char *line);
int					get_size_map(t_config *config, char *line);
void				allocate_map(t_config *config);
int					fill_map(t_config *config);
#endif
