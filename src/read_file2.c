/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:16:46 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 21:41:02 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>
#include <ft_utils.h>
#include <read_map.h>

void			rem_space(char *line)
{
	int			i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_iswhitespace(line[i]))
			line[i] = ' ';
		i++;
	}
}

int				read_line(t_config *config, char *line)
{
	int			i;
	char		**spline;
	int			key;

	if (read_line_map(config, line))
		return (0);
	rem_space(line);
	if (!(spline = ft_split(line, ' ')) || line[0] == '\0')
	{
		free(spline);
		return (0);
	}
	if (is_allwhitespace(line))
		return (0);
	key = get_key(spline[0]);
	i = 0;
	if (key == K_R)
		fill_resolution(config, spline);
	else if (key >= K_NO && key <= K_S)
		fill_texture(config, spline, key);
	else if (key == K_F || key == K_C)
		select_ambient(config, line, key);
	free_ambspline(spline);
	line = NULL;
	return (0);
}

void			free_ambspline(char **spline)
{
	int			i;

	i = 0;
	while (spline[i])
	{
		free(spline[i]);
		i++;
	}
	free(spline);
}

unsigned long	rgbtohex(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void			get_colors(t_config *config, t_mlx *mlx)
{
	mlx->ceilcolor = rgbtohex(config->ceilingcolor[0],
							config->ceilingcolor[1],
							config->ceilingcolor[2]);
	mlx->floorcolor = rgbtohex(config->floorcolor[0],
							config->floorcolor[1],
							config->floorcolor[2]);
}
