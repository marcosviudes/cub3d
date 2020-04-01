#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

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

}					t_list;
typedef struct      s_map
{
    char            **map;
}                   t_map;

#endif