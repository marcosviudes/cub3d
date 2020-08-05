/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:16:54 by mviudes           #+#    #+#             */
/*   Updated: 2020/08/05 13:36:03 by mviudes          ###   ########.fr       */
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

# define MAX_WIDHT 2560
# define MAX_HEIGHT 1395
# define MAX_COLOR_RANGE 255

# define K_R 	1
# define K_NO	2
# define K_SO	3
# define K_WE	4
# define K_EA	5
# define K_S	6
# define K_F	7
# define K_C	8
# define K_MAP	9

# define VALID_CHAR_MAP " 012NSEW"

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
	double			posx;
	double			posy;
	struct s_dir	*next;

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
	t_map			map;
	t_flags			flags;
	t_dir			init_pos;
}					t_config;

int					read_line(t_config *config, char *line);
int					get_key(char* spline);
int					fill_resolution(t_config *config, char **spline);
//int				fill_ambientcolor(t_config *config, char **spline);
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
#endif