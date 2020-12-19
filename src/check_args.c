#include <cub3d.h>

void    check_args(int argc, char *argv[], int fd){
	if(argc != 2 && argc != 3)
			error_exit("Invalid Num of Args");
	if(argc == 3)
		if(ft_strncmp(argv[2], SAVE, SAVE_LEN))
			error_exit("Invalid args use: --save");
    if(fd <= 0)
			error_exit("File not found.");

}