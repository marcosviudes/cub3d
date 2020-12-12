/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 10:37:40 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/12 10:37:44 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <mlx.h>

void get_textures(t_config *config, t_mlx *mlx){

    char *tex_paths[5];
    int i;

    i = 0;
    tex_paths[0] = config->tex_path_east;
    tex_paths[1] = config->tex_path_north;
    tex_paths[2] = config->tex_path_south;
    tex_paths[3] = config->tex_path_west;
    tex_paths[4] = config->tex_sprite;
    while(i < 5)
    {
        mlx->tex[i].img = mlx_xpm_file_to_image(mlx->mlx, tex_paths[i], &mlx->tex[i].img_widht, &mlx->tex[i].img_height);
        if(!mlx->tex[i].img){
            printf("No se ha podido abrir la textura %s\n", tex_paths[i]);
            exit(-1);
        }
        mlx->tex[i].img_addr = mlx_get_data_addr(mlx->tex[i].img, &mlx->tex[i].bpp, &mlx->tex[i].line_lenght, &mlx->tex[i].endian);
        i++;
    }
    return;
}
