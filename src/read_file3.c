/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:40:39 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 21:41:16 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>
#include <ft_utils.h>
#include <read_map.h>

int				read_line_map(t_config *config, char *line)
{
	int			i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_isdigit(line[i]) || config->flags.readingmap == 1)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] == '\t')
				error_exit("tabs on map");
			i++;
		}
		read_map(config, line);
		return (1);
	}
	return (0);
}
