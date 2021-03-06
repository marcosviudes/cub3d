/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 12:25:21 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/20 12:27:32 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	check_args(int argc, char *argv[], int fd)
{
	if (argc != 2 && argc != 3)
		error_exit("Invalid Num of Args");
	if (argc == 3 && ft_strncmp(argv[2], SAVE, SAVE_LEN))
		error_exit("Invalid args use: --save");
	if (fd <= 0)
		error_exit("File not found.");
}
