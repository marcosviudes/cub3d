/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ambientcolor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:48:09 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 21:22:23 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void			fill_ambcheck(char *line)
{
	int			i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_isdigit(line[i]) && line[i] != ',')
			error_exit("Not valid color format");
		i++;
	}
}

char			*fillambientcolorsub(char *line)
{
	int len;

	len = ft_strlen(line);
	len--;
	while (line[len] == ' ')
	{
		line[len] = '\0';
		len--;
	}
	while (*line == ' ')
		line++;
	line += 2;
	while (*line == ' ')
		line++;
	return (line);
}

int				fill_ambientcolor(int *color, char *line)
{
	int			i;
	char		**numbers;
	int			rgb[3];

	line = fillambientcolorsub(line);
	if (ft_charcount(line, ',') != 2)
		error_exit("Not valid color format");
	fill_ambcheck(line);
	numbers = ft_split(line, ',');
	if (!numbers[0] || !numbers[1] || !numbers[2] || numbers[3])
		error_exit("Not valid color format");
	get_fillamb(numbers, rgb);
	i = 0;
	while (i < 3)
	{
		color[i] = rgb[i];
		i++;
	}
	free(numbers);
	return (0);
}

void			get_fillamb(char **numbers, int *rgb)
{
	int			i;

	i = 0;
	while (i < 3)
	{
		if (!numbers[i])
			rgb[i] = -1;
		else if (ft_strisnum(numbers[i]))
			rgb[i] = ft_atoi(numbers[i]);
		else
			rgb[i] = -1;
		free(numbers[i]);
		i++;
	}
}
