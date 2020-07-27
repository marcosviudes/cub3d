#include <cub3d.h>
#include <ft_utils.h>
#include <libft.h>
#include <stdlib.h>


int ft_iswhitespace(int c)
{
    if ((c == ' ') || (c == '\t') || (c == '\n')
			|| (c == '\r') || (c == '\v') || (c == '\f'))
        return(1);
    return(0);
}
int ft_strisnum(char *string)
{
    int i;
    
    i = 0;
    while(string[i] != '\0')
    {
        if(!(string[i] >= '0' && string[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

int		ft_cmpstr(char* string1, char* string2)
{
	int i;

	i = 0;
	if(string1 && string2)
	{
		while(string1[i] != '\0' || string2[i] != '\0')
		{
			if(string1[i] != string2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}/*
int ft_strisnum(char *string)
{
    int i;
    
    i = 0;
    while(string[i] != '\0')
    {
        if(string[i] >= '0' && string[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}
*/