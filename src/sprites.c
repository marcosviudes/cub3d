/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:57:03 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/13 13:43:04 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <draw_utils.h>

void    draw_sprites(t_mlx *mlx)
{
    int spriteheight;
    int spritewidth;
    int first_y;
    int last_y;
    int first_x;
    int last_x;
    int spritex;
    int spritey;
    int x;
    int y;
    
    mlx->sprite[0].dist = pow((mlx->player.posx - mlx->sprite[0].x), 2) + 
                        pow((mlx->player.posy - mlx->sprite[0].y), 2);
                        
    spriteheight = abs((int)(mlx->config->resolutionheight / mlx->sprite[0].dist));
    spritewidth =  abs((int)(mlx->config->resolutionwidht / mlx->sprite[0].dist));
    
    first_y = (-spriteheight /2) + (mlx->config->resolutionheight / 2);
    if(first_y < 0)
			first_y = 0;
	last_y = (spriteheight / 2) + (mlx->config->resolutionheight / 2);
	if(last_y >= mlx->config->resolutionheight)
			last_y = mlx->config->resolutionheight - 1;

    first_x=  (-spritewidth / 2) + mlx->config->resolutionwidht;
    if (first_x < 0)
		first_x = 0;
	last_x = spritewidth / 2 + mlx->config->resolutionwidht;
	if (last_x >= mlx->config->resolutionwidht)
		last_x = mlx->config->resolutionwidht - 1;

    x = first_x;
    while(x < last_x)
    {
        spritex = (int)(256 * (x - (-spritewidth / 2
			+ mlx->config->resolutionwidht)) * mlx->sprite[0].tex.img_widht / spritewidth) / 256;
        y = first_y;
        if (mlx->sprite[0].dist > 0 && x > 0 && x < mlx->config->resolutionwidht &&
			mlx->sprite[0].dist < mlx->sprite_buff[x])
            while (y < last_y)
			{
				spritey = ((((y) * 256 - mlx->config->resolutionheight * 128 + spriteheight * 128) *
				mlx->sprite[0].tex.img_height) / spriteheight) / 256;
				if (mlx->sprite[0].tex.img_addr[4 * (spritex + 64 * spritey)]
				!= (char)0)
					ft_memcpy(mlx->img_addr + 4 * mlx->config->resolutionwidht * y + x * 4,
						&mlx->sprite[0].tex.img_addr[spritey % mlx->sprite[0].tex.img_height *
						mlx->sprite[0].tex.line_lenght + spritex % mlx->sprite[0].tex.img_widht
						* mlx->sprite[0].tex.bpp / 8], sizeof(int));
				y++;
			}
        x++;
    }
    //printf("%d\n", mlx->tex[4].img_height);
    return;
}