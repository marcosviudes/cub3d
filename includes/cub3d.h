/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:16:54 by mviudes           #+#    #+#             */
/*   Updated: 2020/11/19 13:14:53 by mviudes          ###   ########.fr       */
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
# include <ft_math.h>


# define WIN_NAME "CUB3D"
# define F_EXT	 ".cub"

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_F			3
# define KEY_ONE		18
# define KEY_TWO		19
# define KEY_TRHEE		20
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_ESC		53
# define KEY_SHIFT		257

# define KEY_PRESS		2
# define KEY_RELEASE	3

# define ROT_CONST		0.00872665
# define MOV			10
# define MOV_SPEED		1
# define ROT_SPEED		1.5

# define FOV			60
# define P_HEIGHT		0.5
# define CHUNK_SIZE 	59

# define IS_RIGHT		> 0
# define IS_LEFT		< 0
# define IS_UP			> 0
# define IS_DOWN		< 0

# define RED			0x00ff0000
# define GREEN			0x0049ff00
# define BLUE			0x00002eff
# define PINK			0x00ff00dc

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

typedef struct		s_move
{
	int				forward;
	int				backwards;
	int				left;
	int				right;
	int				rotleft;
	int				rotright;
}					t_move;


typedef struct		s_player
{
	double			posx;
	double			posy;
	int				mapx;
	int				mapy;
	float			angle;
	double			height;
	int				distoplane;
	struct s_pos	dir;
	struct s_pos	lastdir;

}					t_player;

typedef struct		s_plane
{
	int				height;
	int				widht;
}					t_plane;

typedef struct		s_sprite
{
	t_dir			pos;
}					t_sprite;

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
	int				spritecount;
	t_pos			init_pos;
	t_sprite		*sprite;
	t_map			map;
	t_flags			flags;
}					t_config;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_addr;
	int     		bpp;
	int 		    line_lenght;
	int		    	endian;
	t_config		*config;
	t_player		player;
	t_move			move;
	t_plane			plane;
}					t_mlx;

int					read_line(t_config *config, char *line);
int					get_key(char* spline);
int					fill_resolution(t_config *config, char **spline);
void				check_extension(char *path, char *ext);
void				fill_texture(t_config *config, char **spline, int key);
void				check_resolution(t_config *config);
void				check_textures(t_config *config);
void				check_direction(t_config *config);
int					check_floor(t_config *config);
int					check_ceiling(t_config *config);


int					check_textures_north(t_config *config);

void				get_init_position(t_config *config, int widht, int height);
int					fill_ambientcolor(int *color, char **spline);
int					select_ambient(t_config *config, char *line, char **spline, int key);
void				free_all_config(t_config  *config);
int					map_fill_with(t_config *config, char c);
int					check_map_walls(t_config *config);
void				get_sprites(t_config *config);

int					engine(t_mlx *mlx);
int					press_key(int key, t_mlx *mlx);
int					release_key(int	key, t_mlx *mlx);
int					init_player(t_config *config, t_mlx *mlx);
void				move_player(t_mlx *mlx);
void				error_exit(char *error);
void				start_dir(char init_dir, t_mlx *mlx);

void				raycasting(t_mlx *mlx);	
#endif