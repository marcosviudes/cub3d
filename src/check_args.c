#include <cub3d.h>

void    check_args(int argc, char *argv[], int fd){
	if(argc != 2 && argc != 3)
		{
			printf("Numero de argumentos invalidos\n");
			return;
		}
	if(argc == 3)
	{
		if(ft_strncmp(argv[2], SAVE, SAVE_LEN))
			{
				printf("Argumento invalido\n");
				return;
			}
		
	}
    if(fd <= 0)
		{
			printf("no se encontro archivo\n");
			return;
		}
}