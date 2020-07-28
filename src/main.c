/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:24:28 by mviudes           #+#    #+#             */
/*   Updated: 2020/07/28 12:21:25 by mviudes          ###   ########.fr       */
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
    fd = open(argv[1] , O_RDONLY);
    
    config = (t_config *)calloc(1, sizeof(t_config));
    while((config->lastline = get_next_line(fd, &line)) > 0)
    {
        read_line(config, line);
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
    printf("\nChecks----------:\n");
    check_resolution(config);
    check_textures(config);
    check_floor(config);
    check_ceiling(config);
    return (0);
}
    
/*cuando quitas NO del file, sprite se vuelve null;*/
//Arreglar atoi qu no funicon a con el debug