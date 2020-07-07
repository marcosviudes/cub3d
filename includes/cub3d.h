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
    char            **map;
}                   t_map;

int      read_line(t_config *config, char *line);
int     check_resolution(t_config *config, char line);
#endif