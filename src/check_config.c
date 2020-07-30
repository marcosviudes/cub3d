/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:10:15 by mviudes           #+#    #+#             */
/*   Updated: 2020/07/30 12:07:17 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void		check_resolution(t_config *config)
{
	if (config->flags.resolution > 1)
		printf("se ha encontrado mas de un resolucion\n");
	if (config->flags.resolution <= 0)
		printf("No se ha encontrado resolucion\n");
	if (config->resolutionwidht > MAX_WIDHT
		|| config->resolutionwidht > MAX_HEIGHT)
	{
		config->resolutionwidht = MAX_WIDHT;
		config->resolutionwidht = MAX_HEIGHT;
	}
	if (config->resolutionwidht == 0 && config->resolutionwidht == 0)
		printf("Resolucion invalida\n");
	if (config->resolutionwidht == -1 || config->resolutionwidht == -1)
		printf("faltan numeros de resolucion\n");
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


void		check_textures(t_config *config)
{

}
