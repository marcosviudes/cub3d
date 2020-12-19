/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:50:01 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/17 12:15:03 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <mlx.h>

void				screenshot(t_mlx *mlx){
	
    take_screenshot(mlx);
}
void	write_data_header(t_mlx *mlx, int size, int fd)
{
	unsigned char header[54];

	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(size);
	header[3] = (unsigned char)(size >> 8);
	header[4] = (unsigned char)(size >> 16);
	header[5] = (unsigned char)(size >> 24);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(mlx->config->resolutionwidht);
	header[19] = (unsigned char)(mlx->config->resolutionwidht >> 8);
	header[20] = (unsigned char)(mlx->config->resolutionwidht >> 16);
	header[21] = (unsigned char)(mlx->config->resolutionwidht >> 24);
	header[22] = (unsigned char)(-mlx->config->resolutionheight);
	header[23] = (unsigned char)(-mlx->config->resolutionheight >> 8);
	header[24] = (unsigned char)(-mlx->config->resolutionheight >> 16);
	header[25] = (unsigned char)(-mlx->config->resolutionheight >> 24);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	write(fd, header, 54);
}

void	take_screenshot(t_mlx *mlx)
{
	int		fd;
	int		res;
	int		size;
	char	*tmp;
    int     widht;

	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0777)) < 0)
		error_exit("no se pudo hacer la captura de pantalla");
	widht = mlx->config->resolutionwidht;
	size = 54 + (widht + mlx->config->resolutionheight) * 4;
	write_data_header(mlx, size, fd);
	tmp = (char *)mlx->img_addr;
	write(fd, tmp, (widht * mlx->config->resolutionheight * 4));
	close(fd);
	exit(EXIT_SUCCESS);
}