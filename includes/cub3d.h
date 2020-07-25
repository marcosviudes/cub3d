#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <libft.h>
# include <get_next_line.h>

#define MAX_WIDHT 2560
#define MAX_HEIGHT 1395


typedef struct      s_config
{
    int             ResolutionWidht;
    int             ResolutionHeight;
    char            *tex_path_north;
    char            *tex_path_south;
    char            *tex_path_west;
    char            *tex_path_east;
	char			*tex_sprite;
    int			    floor[3];
	int 			ceiling[3];
	struct t_map	*map;
	struct t_flags	*flags;
	int				resolutionflag;
    int             floorflag;
    int             cealingflag;
    int             texturenorthflag;
    int             texturesouthflag;
    int             texturewestflag;
    int             textureeastflag;
    int             texturespriteflag;
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
	char			*mapbuff;
    char            **map;

}                   t_map;    

typedef struct		s_flags
{
    int				resolution;
}					t_flags;

int      read_line(t_config *config, char *line);
int     check_resolution(t_config *config, char line);
int		read_map(t_config *config, char	*line);
int		ft_cmpstr(char *string1, char *string2);
#endif