/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:16:54 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/21 21:44:26 by mviudes          ###   ########.fr       */
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
# include <mlx.h>

# define WIN_NAME 		"CUB3D"
# define F_EXT	 		".cub"
# define TEX_EXT		".xpm"
# define SAVE			"--save"
# define SAVE_LEN		7

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

# define MIN_RES		50
# define MAX_WIDTH		2560
# define MAX_HEIGHT		1395
# define MAX_COLOR_RNG	255

# define KEY_PRESS		2
# define KEY_RELEASE	3

# define ROT_CONST		0.174533
# define ROT_SPEED		1.8
# define MOV_DEF		.33
# define MOV_SPEED		1
# define DEF_HIGHT		0.5

# define FOV			60
# define P_HEIGHT		0.5
# define CHUNK_SIZE 	64

# define RED			0x00ff0000
# define GREEN			0x0049ff00
# define BLUE			0x00002eff
# define PINK			0x00ff00dc

typedef struct			s_pos
{
	double				x;
	double				y;
}						t_pos;

typedef struct			s_dir
{
	int					x;
	int					y;
}						t_dir;

typedef struct			s_move
{
	int					forward;
	int					backwards;
	int					left;
	int					right;
	int					rotleft;
	int					rotright;
}						t_move;

typedef struct			s_player
{
	double				posx;
	double				posy;
	int					mapx;
	int					mapy;
	float				angle;
	double				height;
	double				speed;
	int					distoplane;
	struct s_pos		dir;
	struct s_pos		lastdir;

}						t_player;

typedef struct			s_plane
{
	double					oldx;
	double					oldy;
	double					x;
	double					y;
}						t_plane;

typedef struct			s_tex
{
	void				*img;
	char				*img_addr;
	int					bpp;
	int					endian;
	int					line_lenght;
	int					img_width;
	int					img_height;

}						t_tex;

typedef struct			s_sprite
{
	int					id;
	double				dist;
	double				x;
	double				y;
	t_tex				tex;
}						t_sprite;

typedef struct			s_lstbuff
{
	char				*line;
	struct s_lstbuff	*next;
}						t_lstbuff;

typedef struct			s_map
{
	float				map_size;
	int					**map;
	int					max_height;
	int					max_width;
	t_lstbuff			*buff;
}						t_map;

typedef struct			s_flags
{
	int					resolution;
	int					floor;
	int					cealing;
	int					texturenorth;
	int					texturesouth;
	int					texturewest;
	int					textureeast;
	int					texturesprite;
	int					readingmap;
	int					initpos;
	int					screenshot;
}						t_flags;

typedef struct			s_config
{
	int					lastline;
	int					resolutionwidth;
	int					resolutionheight;
	char				*tex_path_north;
	char				*tex_path_south;
	char				*tex_path_west;
	char				*tex_path_east;
	char				*tex_sprite;
	int					floorcolor[3];
	int					ceilingcolor[3];
	char				init_dir;
	int					spritecount;
	t_dir				init_pos;
	t_sprite			*sprite;
	t_map				map;
	t_flags				flags;
}						t_config;
typedef struct			s_ray
{
	double				dirx;
	double				diry;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	double				walldist;

}						t_ray;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*img_addr;
	int					bpp;
	int					line_lenght;
	int					endian;
	int					prueba;
	int					enablesprite;
	int					ceilcolor;
	int					floorcolor;
	int					firstpix;
	int					lastpix;
	int					lineheight;
	double				*sprite_buff;
	int					x;
	double				spritex;
	double				spritey;
	double				invdet;
	int					sprt_firsty;
	int					sprt_lasty;
	int					sprt_firstx;
	int					sprt_lastx;
	double				sprt_transfx;
	double				sprt_transfy;
	int					sprt_screenx;
	int					sprt_height;
	int					sprt_width;
	int					sprt_texx;
	int					sprt_texy;
	int					sprt_i;
	t_sprite			*sprite;
	t_tex				tex[5];
	t_ray				ray;
	t_config			*config;
	t_player			player;
	t_move				move;
	t_plane				plane;
}						t_mlx;

int						read_line(t_config *config, char *line);
int						get_key(char *spline);
int						fill_resolution(t_config *config, char **spline);
void					check_extension(char *path, char *ext);
void					fill_texture(t_config *config, char **spline, int key);
void					fill_texture2(t_config *config, int key, char *texture);
void					check_resolution(t_config *config);
void					check_textures(t_config *config);
void					check_direction(t_config *config);
int						check_floor(t_config *config);
int						check_ceiling(t_config *config);
void					check_args(int argc, char *argv[], int fd);

int						check_textures_north(t_config *config);
int						check_textures_south(t_config *config);
int						check_textures_west(t_config *config);
int						check_textures_east(t_config *config);
int						check_textures_sprite(t_config *config);
void					get_textures(t_config *config, t_mlx *mlx);

void					get_init_position(t_config *config,
										int width, int height);
int						fill_ambientcolor(int *color, char *line);
int						select_ambient(t_config *config, char *line, int key);
void					free_all_config(t_config *config);
int						map_fill_with(t_config *config, char c);
void					check_map_walls(t_config *config);
void					check_map_walls2(t_config *config);
void					get_sprites(t_config *config);
void					countmap_sprites(t_config *config);
void					save_sprites(t_config *config);
int						engine(t_mlx *mlx);
int						press_key(int key, t_mlx *mlx);
int						release_key(int	key, t_mlx *mlx);
int						init_player(t_config *config, t_mlx *mlx);
void					move_player(t_mlx *mlx);
void					error_exit(char *error);
void					start_dir(char init_dir, t_mlx *mlx);

void					raycasting(t_mlx *mlx);
int						get_text_id(int side, float dirx, float diry);

void					draw_sprites(t_mlx *mlx);

void					screenshot(t_mlx *mlx);
void					write_data_header(t_mlx *mlx, int size, int fd);
void					take_screenshot(t_mlx *mlx);

void					get_colors(t_config *config, t_mlx *mlx);
unsigned long			rgbtohex(int r, int g, int b);

int						exit_succes(t_mlx *mlx);

void					star_dir2(char init_dir, t_mlx *mlx);
int						ft_iswhitespace(int c);
int						is_allwhitespace(char *line);
void					print_texture(t_mlx *mlx, int height, int width, int x);

void					player_movforward(t_mlx *mlx, double speed);
void					player_movback(t_mlx *mlx, double speed);
void					player_movleft(t_mlx *mlx, double speed);
void					player_movright(t_mlx *mlx, double speed);
void					player_rotright(t_mlx *mlx);
void					player_rotleft(t_mlx *mlx);

void					spritedistcalc(t_mlx *mlx);
void					order_sprites(t_mlx *mlx);
void					fill_map_sub(t_config *config, int row, int i, char c);
int						ft_strisnum(char *string);
void					get_fillamb(char **numbers, int *rgb);
void					free_ambspline(char **spline);
int						read_line_map(t_config *config, char *line);
#endif
