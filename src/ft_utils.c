#include <cub3d.h>
#include <ft_utils.h>
#include <libft.h>


int ft_iswhitespace(int c)
{
    if ((c == ' ') || (c == '\t') || (c == '\n')
			|| (c == '\r') || (c == '\v') || (c == '\f'))
        return(1);
    return(0);
}
char    **ft_getsubstrings(char *string)
{/*
    char **substrings;
    int i = 0;
    int j = 0;
	int word = 0;
    int len;
	char *temp;

    len = ft_strlen(*substrings);
	temp = (char *)malloc(sizeof(len));
    while(string[i] != '\0')
    {
        if(string[i] == ' ' || string[i] == ',')
		{
			temp[i] = '\0';
			word++;
			substrings[word] = ft_strdup(temp);
		}
		else 
			temp[i] = string[i];
		i++;        
    }
    return(&*substrings);
 */
   return 0;
}
