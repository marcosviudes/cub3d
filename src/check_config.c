/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:10:15 by mviudes           #+#    #+#             */
/*   Updated: 2020/10/05 14:26:00 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <read_map.h>
#include <ft_utils.h>

void		check_resolution(t_config *config)
{
	if (config->flags.resolution > 1)
		printf("se ha encontrado mas de un resolucion\n");
	if (config->flags.resolution <= 0)
		printf("No se ha encontrado resolucion\n");
	if (config->resolutionwidht == 0 && config->resolutionheight == 0)
		printf("Resolucion invalida\n");
	if (config->resolutionwidht == -1 || config->resolutionheight == -1)
		printf("faltan numeros de resolucion\n");
	if (config->resolutionwidht > MAX_WIDHT
		|| config->resolutionheight > MAX_HEIGHT)
	{
		config->resolutionwidht = MAX_WIDHT;
		config->resolutionheight = MAX_HEIGHT;
	}
}

int			check_floor(t_config *config)
{
	int		i;

	i = 0;
	if (config->flags.floor > 1)
		printf("se han encontrado mas de una configuracion pra el suelo\n");
	if (config->flags.floor <= 0)
		printf("No se ha encontrado colores para el suelo\n");
	while (i < 3)
	{
		if (config->floorcolor[i] <= 0)
			printf("los colores del suelo deben ser mayor a 0\n");
		if (config->floorcolor[i] > MAX_COLOR_RANGE)
			printf("los colores de suelo no pueden ser mayor a 255\n");
		i++;
	}
	return (0);
}

int			check_ceiling(t_config *config)
{
	int		i;

	i = 0;
	if (config->flags.cealing > 1)
		printf("se han encontrad mas de una configuracion para el techo\n");
	if (config->flags.cealing <= 0)
		printf("No se ha encontrado colores para el techo\n");
	while (i < 3)
	{
		if (config->ceilingcolor[i] <= 0)
			printf("los colores del techo deben ser mayor a 0\n");
		if (config->ceilingcolor[i] > MAX_COLOR_RANGE)
			printf("los colores techo no pueden ser mayor a 255\n");
		i++;
	}
	return (0);
}

int			check_textures_north(t_config *config)
{
	if (config->flags.texturenorth > 1)
		printf("se ha encontrado mas de una textura N\n");
	else if (config->flags.texturenorth <= 0)
		printf("no se ha encontrado textura NO\n");
	else if (config->flags.texturenorth == 1 && !config->tex_path_north)
		printf ("textura N invalida\n");
	else if (!config->tex_path_north)
		printf ("debe introducir una textura N\n");
	return (1);
}

int			check_textures_south(t_config *config)
{
	if (config->flags.texturesouth > 1)
		printf("se ha encontrado mas de una textura SO\n");
	else if (config->flags.texturesouth <= 0)
		printf("no se ha encontrado textura SO\n");
	else if (config->flags.texturesouth == 1 && !config->tex_path_south)
		printf ("textura SO invalida\n");
	else if (!config->tex_path_south)
		printf ("debe introducir una textura SO\n");
	return (1);
}
int			check_textures_west(t_config *config)
{
	if (config->flags.texturewest > 1)
		printf("se ha encontrado mas de una textura WE\n");
	else if (config->flags.texturewest <= 0)
		printf("no se ha encontrado textura WE\n");
	else if (config->flags.texturewest == 1 && !config->tex_path_west)
		printf ("textura WE invalida\n");
	else if (!config->tex_path_west)
		printf ("debe introducir una Textura W\n");
	return (1);
}
int			check_textures_east(t_config *config)
{
	if (config->flags.textureeast > 1)
		printf("se ha encontrado mas de una textura EA\n");
	else if (config->flags.textureeast <= 0)
		printf("no se ha encontrado textura EA\n");
	else if (config->flags.textureeast == 1 && !config->tex_path_east)
		printf ("Textura EA invalida\n");
	else if (!config->tex_path_east)
		printf ("debe introducir una textura EA\n");
	return (1);
}

int			check_textures_sprite(t_config *config)
{
	if (config->flags.texturesprite > 1)
		printf("se ha encontrado mas de una textura S\n");
	else if (config->flags.texturesprite <= 0)
		printf("no se ha encontrado textura S\n");
	else if (config->flags.texturesprite == 1 && !config->tex_sprite)
		printf ("textura S invalida\n");
	else if (!config->tex_sprite)
		printf ("debe introducir una textura S\n");
	return (1);
}
void		check_textures(t_config *config)
{
	check_textures_north(config);
	check_textures_south(config);
	check_textures_west(config);
	check_textures_east(config);
	check_textures_sprite(config);
}
void		free_map(t_map map){
	return; 
}
void		free_all_config(t_config *config)
{
	ft_nullfree(config->tex_path_north);
	ft_nullfree(config->tex_path_east);
	ft_nullfree(config->tex_path_south);
	ft_nullfree(config->tex_path_west);
	ft_nullfree(config->floorcolor);
	ft_nullfree(config->ceilingcolor);
	free_map(config->map);
}