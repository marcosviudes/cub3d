/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:08:31 by mviudes           #+#    #+#             */
/*   Updated: 2020/07/20 11:20:25 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <libft.h>

int				get_next_line(int fd, char **line)
{
	static char	*str[4096];
	char		buff[BUFFER_SIZE + 1];
	int			i;
	char		*tmp;

	!str[fd] ? str[fd] = ft_strcdup("", '\0') : str[fd];
	while ((i = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[i] = '\0';
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		if (ft_strchr((str[fd] = tmp), '\n'))
			break ;
	}
	if (i < 0 || line == NULL)
		return (-1);
	*line = ft_strcdup(str[fd], '\n');
	tmp = NULL;
	if (str[fd][ft_strlen(*line)] != '\0')
		tmp = ft_strcdup(ft_strchr(str[fd], '\n') + 1, '\0');
	free(str[fd]);
	if ((str[fd] = tmp) == NULL)
		return (0);
	return (1);
}
