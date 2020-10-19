/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:24:28 by mviudes           #+#    #+#             */
/*   Updated: 2020/10/17 13:43:08 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <get_next_line.h>
#include <ft_utils.h>
#include <mlx.h>
#include <read_map.h>
#include <draw_utils.h>
#include <draw_map.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int         fd;
	char        *line;
	t_config    *config;
	t_mlx		*mlx;

	int         lastline;
	fd = open(argv[1] ,O_RDONLY);
	
	config = /*(t_config *)*/ft_calloc(1, sizeof(t_config));
	while((config->lastline = get_next_line(fd, &line)) > EOF)
	{
		read_line(config, line);
		free(line);
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
	printf("La posicion  inicial es  : |%ix%i|\n", (int)config->init_pos.x, (int)config->init_pos.y);
	printf("la dirccion inicial es 	 : %c\n", config->init_dir);
	print_sprites(config);
	printf("\nChecks----------:\n\n");
	check_resolution(config);
	check_textures(config);
	check_floor(config);
	check_ceiling(config);
	check_map_walls(config);
	check_direction(config);
	print_map(config);
	
	mlx = (t_mlx*)calloc(1, sizeof(t_mlx));
//	mlx->player = (t_player *)calloc(1, sizeof(t_player));
	mlx->config = config;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, config->resolutionwidht, config->resolutionheight, WIN_NAME);

	init_player(mlx->config, mlx);
	mlx_loop_hook(mlx->mlx, engine, mlx);
	mlx_hook(mlx->win, KEY_PRESS, (1L << 0), press_key,mlx);
	mlx_hook(mlx->win, KEY_RELEASE, (1L << 1), 	release_key , mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

int		print_sprites(t_config *config){
	int	i;

	i = 0;
	printf("sprites-----:\n");
	while(i < config->spritecount){
		printf("\tel sprite [%i] tiene la posicion : x = [%i]; y = [%i];\n", i, config->sprite[i].pos.x, config->sprite[i].pos.y);
		i++;
	}
	printf("El numero de sprties son : -%i-\n", i);
	return 0;
}
int		print_map(t_config *config)
{
	int	i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;

	printf("\nmap---------:\n\n");
	while (j < config->map.max_height)
	{
		while (i < config->map.max_widht)
			{
				printf("%i", config->map.map[j][i]);
				i++;
				if (i > k)
					k = i;
			}
			printf("\n");
		j++;
		i = 0;
	}
	printf("\n");
	printf("El map printeado mide %ix%i", k, j);
	return(0);
}

void		ft_nullfree(void *ptr){
	ptr = NULL;
	free(ptr);
}

void exerror(char *serror){
	ft_putstr_fd("Error", 1);
	ft_putstr_fd(serror,1);
	write(1, "\n", 1);
	exit(-1);
	}