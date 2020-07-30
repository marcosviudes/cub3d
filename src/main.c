/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:24:28 by mviudes           #+#    #+#             */
/*   Updated: 2020/07/30 23:18:18 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <get_next_line.h>
#include <ft_utils.h>
//#include <mlx.h>

int main(int argc, char *argv[])
{
	int         fd;
	char        *line;
	t_config    *config;
	int         lastline;
	fd = open(argv[1] ,O_RDONLY);
	
	config = (t_config *)calloc(1, sizeof(t_config));
	while((config->lastline = get_next_line(fd, &line)) > EOF)
	{
		read_line(config, line);
		if (!config->lastline)
		break ;
	} 
	
	printf("hasta aqui funciona\n");
	printf("El valor del width es:  -%i-\n", config->resolutionwidht);
	printf("El valor del height es: -%i-\n", config->resolutionheight);
	printf("Los colores del suelo son: -%i- -%i- -%i-\n", config->floorcolor[0], config->floorcolor[1], config->floorcolor[2]);
	printf("Los colores del techo son: -%i- -%i- -%i-\n", config->ceilingcolor[0], config->ceilingcolor[1], config->ceilingcolor[2]);
	printf("La textura del norte es  : %s\n", config->tex_path_north);
	printf("La textura del sur es    : %s\n", config->tex_path_south);
	printf("La textura del este es   : %s\n", config->tex_path_east);
	printf("La textura del oeste es  : %s\n", config->tex_path_west);
	printf("La textura del sprinte es: %s\n", config->tex_sprite);
	printf("El tamaño del mapa es    : |%ix%i|\n", config->map.max_widht, config->map.max_height);
	printf("La posicion  inicial es  : |%ix%i|\n", config->init_pos.x, config->init_pos.y);
	printf("\nChecks----------:\n");
	check_resolution(config);
	check_textures(config);
	check_floor(config);
	check_ceiling(config);
	return (0);
}
	
//¿Existe alguna funcion que al pasarle un char y una string devuelva si ah aencontrado el char en la string?
//¿Existe alguna manera de identar una estrucutra?
//Terminar la lectura del mapa;
//validar el mapa;

//Checkear toda la configuracion;
//Ordenar toda la configuracion;

//Mirar como funcionaa la mlx;

