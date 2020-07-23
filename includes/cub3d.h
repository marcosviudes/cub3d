#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <libft.h>
# include <get_next_line.h>

typedef struct      s_config
{
    int             ResolutionWidht;
    int             ResolutionHeight;
    char            *tex_path_north;
    char            *tex_path_south;
    char            *tex_path_west;
    char            *tex_path_east;
	char			*tex_sprite;
    char			*floor;
	char			*ceiling;
	struct t_map	*map;

}                   t_config;

typedef struct      s_dir
{
    double          x;
    double          y;
}                   t_dir;

typedef struct	    s_player
{
    double          posx;
    double          posy;
    struct s_dir    *next;

}					t_player;
typedef struct      s_map
{
	char			*stringmap;
    char            **map;
}                   t_map;

int      read_line(t_config *config, char *line);
int     check_resolution(t_config *config, char line);
int		read_map(t_config *config, char	*line);
int		ft_cmpstr(char *string1, char *string2);
#endif