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
    while((gnlret = get_next_line(fd, &line)) > 0)
    {
        read_line(config, line);
       
    } 
    checkResolution(config);
    printf("hasta aqui funciona\n");
    printf("El valor del width es:  -%i-\n", config->ResolutionWidht);
    printf("El valor del height es: -%i-\n", config->ResolutionHeight);
    return (0);
}