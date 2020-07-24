#ifndef UTILS_H
# define UTILS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


int         ft_iswhitespace(int c);
char        **ft_getsubstrings(char *string);
int         fillResolution(t_config *config, char **spline);
void		checkResolution(t_config *config);
#endif