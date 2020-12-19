/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:21:05 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/19 12:01:27 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <libft.h>
#include <ft_utils.h>
#include <read_map.h>

int				fill_resolution(t_config *config, char **spline)
{
	int			i;
	int			resolution[3];

	i = 1;
	config->flags.resolution += 1;
	if (spline[3] != NULL)
		return (1);
	while (i < 3)
	{
		if (!spline[i])
			resolution[i] = -1;
		else if (!ft_strisnum(spline[i]))
			resolution[i] = 0;
		else if(ft_strlen(spline[i]) > 5)
			resolution[i] = 10000;
		else
			resolution[i] = ft_atoi(spline[i]);
		i++;
	}
	i = 0;
	config->resolutionwidht = resolution[1];
	config->resolutionheight = resolution[2];
	return (0);
}

void			fill_texture(t_config *config, char **spline, int key)
{
	char *texture;

	if(spline[2] != NULL){
		if (key == K_NO)
			config->flags.texturenorth += 1;
		if (key == K_SO)
			config->flags.texturesouth += 1;
		if (key == K_WE)
			config->flags.texturewest += 1;
		if (key == K_EA)
			config->flags.textureeast += 1;
		if (key == K_S)
			config->flags.texturesprite += 1;
		return;
	}
	texture = ft_strdup(spline[1]);
	while(ft_iswhitespace(*texture)){
		texture++;
	}
	if (key == K_NO)
	{
		config->tex_path_north = texture;
		config->flags.texturenorth += 1;
	}
	else if (key == K_SO)
	{
		config->tex_path_south = texture;
		config->flags.texturesouth += 1;
	}
	else if (key == K_WE)
	{
		config->tex_path_west = texture;
		config->flags.texturewest += 1;
	}
	else if (key == K_EA)
	{
		config->tex_path_east = texture;
		config->flags.textureeast += 1;
	}
	else if (key == K_S)
	{
		config->tex_sprite = texture;
		config->flags.texturesprite += 1;
	}
}



int				read_line(t_config *config, char *line)
{
	int		i;
	char	**spline;
	int		key;

	i = 0;
	while(line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_isdigit(line[i]) || config->flags.readingmap == 1)
	{
		i = 0;
		while(line[i] != '\0'){
			if(line[i] == '\t')
			{
				error_exit("tabs on map");
			}
			i++;
		}
		read_map(config, line);
		return(0);
	}
	i = 0;
	while(line[i] != '\0'){
		if(ft_iswhitespace(line[i])){
			line[i] = ' ';
		}
		i++;
		}
	i = 0;
	if(!(spline = ft_split(line, ' ')) || line[0] == '\0'){
		free(spline);
		return(0);
	}
	key = get_key(spline[0]);
	while (ft_iswhitespace(line[i]))
		i++;
	if (key == K_R)
		fill_resolution(config, spline);
	else if (key >= K_NO && key <= K_S)
		fill_texture(config, spline, key);
	else if (key == K_F || key == K_C)
		select_ambient(config, line, key);
	i = 0;
	while(spline[i]){
		free(spline[i]);
		i++;
	}
	free(spline);
	line = NULL;
	return (0);
}


int				select_ambient(t_config *config, char *line, int key)
{
	int i;

	i = 0;
	if (key == K_F)
	{
		config->flags.floor += 1;
		fill_ambientcolor(config->floorcolor, line);
	}
	else if (key == K_C)
	{
		config->flags.cealing += 1;
		fill_ambientcolor(config->ceilingcolor, line);
	}
		return (0);
}

int				fill_ambientcolor(int *color, char *line)
{
	int i;
	int pos;
	int len;
	char		**numbers;
	int			rgb[3];
	i = 0;
	pos = 0;

	
	len = ft_strlen(line);
	len--;
	while(line[len] == ' ')
	{
		line[len] = '\0';
		len--;
	}
	while(*line == ' ')
			line++;
	line += 2;
	while(*line == ' ')
			line++;
	i = 0;
	if(ft_charcount(line, ',') != 2)
		error_exit("Not valid color format");
	i = 0;
	while(line[i] != '\0'){
			if(!ft_isdigit(line[i]) && line[i]!= ',')
				error_exit("Formato de color invalido");
			i++;
	}

	i = 0;
	numbers = ft_split(line, ',');
	if (!numbers[0] || !numbers[1] || !numbers[2] || numbers[3])
		error_exit("Not valid colro format");
	while (i < 3)
	{
		if(!numbers[i])
			rgb[i] = -1;
		else if(ft_strisnum(numbers[i]))
			rgb[i] = ft_atoi(numbers[i]);
		else
			rgb[i] = -1;
		free(numbers[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		color[i] = rgb[i];
		i++;
	}
	free(numbers);
	return (0);
	return(0);
}
unsigned long rgbtohex(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void		get_colors(t_config *config, t_mlx *mlx){
	mlx->ceilcolor = rgbtohex(config->ceilingcolor[0], config->ceilingcolor[1], config->ceilingcolor[2]);
	mlx->floorcolor = rgbtohex(config->floorcolor[0],config->floorcolor[1],config->floorcolor[2]);
}