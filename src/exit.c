/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:17:31 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/16 10:30:06 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <cub3d.h>

void		kill(void *ptr){
	ptr = NULL;
	free(ptr);
}
void        ace(char *str, ...)
{
    va_list ap;
    va_start(ap, str);
    kill(str);
    while((str = va_arg(ap, char * )))
        kill(str);
    va_end(ap);
}

void error_exit(char *error){
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(error,1);
	exit(-1);
}