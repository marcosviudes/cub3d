#include <cub3d.h>
#include <get_next_line.h>
#include <ft_utils.h>
//#include <mlx.h>

int main(int argc, char *argv[])
{
    int         fd;
    char        *line;
    t_config    *config;
    int         gnlret;
    fd = open(argv[1] , O_RDONLY);
    
    config = (t_config *)calloc(1, sizeof(t_config));
    config->flags = (void *)calloc(1,sizeof(t_flags));
	config->map = (void *)calloc(1,sizeof(t_map));
    while((gnlret = get_next_line(fd, &line)) > 0)
    {
        read_line(config, line);
       
    } 
    checkResolution(config);
    printf("hasta aqui funciona\n");
    printf("El valor del width es:  -%i-\n", config->ResolutionWidht);
    printf("El valor del height es: -%i-\n", config->ResolutionHeight);
    printf("Los colores del suelo son: -%i- -%i- -%i-\n", config->floor[0], config->floor[1], config->floor[2]);
    printf("Los colores del techo son: -%i- -%i- -%i-\n", config->ceiling[0], config->ceiling[1], config->ceiling[2]);
    printf("La textura del norte es  : %s\n", config->tex_path_north);
    printf("La textura del sur es    : %s\n", config->tex_path_south);
    printf("La textura del este es   : %s\n", config->tex_path_east);
    printf("La textura del oeste es  : %s\n", config->tex_path_west);
    printf("La textura del sprinte es: %s\n", config->tex_path_north);

    return (0);
}
    
