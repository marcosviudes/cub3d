/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:16:54 by mviudes           #+#    #+#             */
/*   Updated: 2020/08/17 10:22:47 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <libft.h>
# include <get_next_line.h>

# define FOV	0.66

# define WIN_NAME "CUB3D"

# define KEY_W
# define KEY_A
# define KEY_S
# define KEY_D
# define KEY_F
# define KEY_LEFT
# define KEY_RIGHT
# define KEY_ESC

# define MOV_SPEED
# define ROT_SPEED

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_dir
{
	int				x;
	int				y;
}					t_dir;


typedef struct		s_player
{
	float			posx;
	float			posy;
	struct s_pos	pos;
	struct s_dir	dir;

}					t_player;

typedef struct		s_maperror
{
	int				firstline;
}					t_maperror;

typedef struct 		s_lstbuff
{
	char				*line;
	struct s_lstbuff	*next;
}					t_lstbuff;

typedef struct		s_map
{
	float			map_size;
	int				**map;
	int				max_height;
	int				max_widht;
	t_lstbuff		*buff;
	t_maperror		errors;

}					t_map;

typedef struct		s_flags
{
	int				resolution;
	int				floor;
	int				cealing;
	int				texturenorth;
	int				texturesouth;
	int				texturewest;
	int				textureeast;
	int				texturesprite;
	int				readingmap;
	int				initpos;
}					t_flags;

typedef struct		s_config
{
	int				lastline;
	int				resolutionwidht;
	int				resolutionheight;
	char			*tex_path_north;
	char			*tex_path_south;
	char			*tex_path_west;
	char			*tex_path_east;
	char			*tex_sprite;
	int				floorcolor[3];
	int				ceilingcolor[3];
	char			init_dir;
	t_map			map;
	t_flags			flags;
	t_dir			init_pos;
}					t_config;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	t_config		*config;
	t_player		player;
}					t_mlx;

int					read_line(t_config *config, char *line);
int					get_key(char* spline);
int					fill_resolution(t_config *config, char **spline);
void				fill_texture(t_config *config, char **spline, int key);
void				check_resolution(t_config *config);
void				check_textures(t_config *config);
int					check_floor(t_config *config);
int					check_ceiling(t_config *config);


int					check_textures_north(t_config *config);

void				get_init_position(t_config *config, int widht, int height);
int					fill_ambientcolor(int *color, char **spline);
int					select_ambient(t_config *config, char *line, char **spline, int key);
void				free_all_config(t_config  *config);
int					map_fill_with(t_config *config, char c);
int					check_map_walls(t_config *config);

void				engine(t_mlx *mlx);
#endif