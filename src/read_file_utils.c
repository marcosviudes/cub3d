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
}
// char    **ft_getsubstrings(char *string)
// {
//     char **substrings;
//     int i = 0;
// 	int word = 0;
//     int len;
// 	char *temp = "";

//     len = ft_strlen(string);
// 	if (NULL == (temp = (char *)malloc(sizeof(len))))
//         return (NULL);
//     **substrings = (char*)malloc(sizeof(temp));
//     while(string[i] != '\0')
//     {
//         if(string[i] == ' ' || string[i] == ',')
// 		{
// 			temp[i] = '\0';
// 			substrings[word] = ft_strdup(temp);
// 			word++;
//             temp = NULL;
//             temp = (char *)malloc(sizeof(len));
// 		}
// 		else
//         {
// 			temp[i] = string[i];
//         }
//         i++;        
//     }
//     return(&*substrings);
 
//    return 0;
// }
/*
char    **ft_getsubstrings(char *string)
{
    char **substrings;
    int i = 0;
	int words = 0;
    int len;
	char *temp = 0;

    if (NULL == (temp = (char *)malloc(sizeof(len))))
        return (NULL);
    substrings = (char*)malloc(4*sizeof(temp));
    while(string[i] != '\0')
    {
        if(string[i] == ' '|| string[i] == ',')
        {
            temp[i] = '\0';
            substrings[words] = (char*)malloc(sizeof(temp + 1));
            substrings[words] = temp;
            words++;
            temp = ft_calloc(1, sizeof(len));
        }
        else 
        {
            temp[i] = string[i];
        }
        i++;
    }
    return(&*substrings);
 
   return 0;
}*/