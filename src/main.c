/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:24:28 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/22 11:01:39 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <get_next_line.h>
#include <ft_utils.h>
#include <mlx.h>
#include <read_map.h>
#include <draw_utils.h>
#include <math.h>

void			getparams(t_config *config, int fd)
{
	int			readcount;
	char		*line;

	readcount = 0;
	while ((config->lastline = get_next_line(fd, &line)) > EOF)
	{
		read_line(config, line);
		free(line);
		readcount++;
		if (!config->lastline)
			break ;
	}
	if (readcount < 8)
		error_exit("Not valid file");
	check_resolution(config);
	check_textures(config);
	check_floor(config);
	check_ceiling(config);
	check_map_walls(config);
	check_direction(config);
}

int				main(int argc, char *argv[])
{
	int			fd;
	t_config	*config;
	t_mlx		*mlx;

	fd = open(argv[1], O_RDONLY);
	check_args(argc, argv, fd);
	check_extension(argv[1], F_EXT);
	config = ft_calloc(1, sizeof(t_config));
	mlx = (t_mlx*)calloc(1, sizeof(t_mlx));
	getparams(config, fd);
	mlx->mlx = mlx_init();
	mlx->config = config;
	mlx->sprite = config->sprite;
	get_textures(mlx->config, mlx);
	init_player(mlx->config, mlx);
	if (argc == 3)
		screenshot(mlx);
	mlx->win = mlx_new_window(mlx->mlx, config->resolutionwidth,
							config->resolutionheight, WIN_NAME);
	mlx_loop_hook(mlx->mlx, engine, mlx);
	mlx_hook(mlx->win, KEY_PRESS, (1L << 0), press_key, mlx);
	mlx_hook(mlx->win, KEY_RELEASE, (1L << 1), release_key, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
