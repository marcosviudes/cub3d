/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 10:40:51 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/19 11:50:06 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <ft_utils.h>
#include <libft.h>
#include <stdlib.h>
#include <read_map.h>

int		ft_iswhitespace(int c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n')
			|| (c == '\r') || (c == '\v') || (c == '\f'))
		return (1);
	return (0);
}

int		ft_strisnum(char *string)
{
	int i;

	i = 0;
	if(!string)
		return (0);
	while (string[i] != '\0')
	{
		if (!(string[i] >= '0' && string[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int		ft_cmpstr(char *string1, char *string2)
{
	int i;

	i = 0;
	if (!string1 || !string2)
		return (0);
	while (string1[i] != '\0' || string2[i] != '\0')
	{
		if (string1[i] != string2[i])
			return (0);
		i++;
	}
	return (1);
}

int		get_key(char *spline)
{
	if (ft_cmpstr(spline, "R"))
		return (K_R);
	if (ft_cmpstr(spline, "NO"))
		return (K_NO);
	if (ft_cmpstr(spline, "SO"))
		return (K_SO);
	if (ft_cmpstr(spline, "WE"))
		return (K_WE);
	if (ft_cmpstr(spline, "EA"))
		return (K_EA);
	if (ft_cmpstr(spline, "S"))
		return (K_S);
	if (ft_cmpstr(spline, "F"))
		return (K_F);
	if (ft_cmpstr(spline, "C"))
		return (K_C);
	else
		error_exit("key invalida");
		exit(-1);
	return (0);
}

int			find_char_str(char c, char const *string)
{
	int		i;

	i = 0;
	while(string[i] != '\0')
		{
			if (string[i] == c)
				return (c);
			i++;
		}
	return (0);
}

void ft_remchar(char *string, char c)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (string[i])
    {
        if (string[i] != c) 
            string[j++] = string[i];
        i++;       
    }
    string[j]=0;
}