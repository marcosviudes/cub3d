#include <cub3d.h>
#include <get_next_line.h>
#include <ft_utils.h>

int main(int argc, char *argv[])
{
    int         fd;
    char        *line;
    t_config    *config;

    fd = open(argv[1] , O_RDONLY);
    
    while(get_next_line(fd, &line) > 0)
    {
        read_line(config, line);
    }
    printf("hasta aqui funciona");
    return (0);
}