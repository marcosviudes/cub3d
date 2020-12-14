/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:57:03 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/14 14:35:01 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <draw_utils.h>

void    draw_sprites(t_mlx *mlx)
{
    int spriteheight;
    int spritewidth;
    double spritex;
    double spritey;
    double invdet;
    int first_y;
    int last_y;
    int first_x;
    int last_x;
    int sp_texx;
    int sp_texy;
    int x;
    int y;
    int i;

    i = 0;
    while(i < mlx->config->spritecount){
    spritex = mlx->sprite[i].x - mlx->player.posx;
    spritey = mlx->sprite[i].y - mlx->player.posy;
    invdet = 1.0 / (mlx->plane.x * mlx->player.dir.y - mlx->player.dir.x * mlx->plane.y);

      double transformx = invdet * (mlx->player.dir.y * spritex - mlx->player.dir.x * spritey);
      double transformy = invdet * (-mlx->plane.y * spritex + mlx->plane.x * spritey);
      int spritescreenx = (int)((mlx->config->resolutionwidht / 2) * (1 + transformx / transformy));
    spriteheight = abs((int)(mlx->config->resolutionheight/(transformy)));
    first_y = (-spriteheight /2) + (mlx->config->resolutionheight / 2);
    if(first_y < 0)
			first_y = 0;
	last_y = (spriteheight / 2) + (mlx->config->resolutionheight / 2);
	if(last_y >= mlx->config->resolutionheight)
			last_y = mlx->config->resolutionheight - 1;
    spritewidth = abs( (int) (mlx->config->resolutionheight / (transformy)));
    first_x = (-spritewidth / 2) + spritescreenx;
    if (first_x < 0)
		first_x = 0;
	last_x = spritewidth / 2 + spritescreenx;
	if (last_x > mlx->config->resolutionwidht)
		last_x = mlx->config->resolutionwidht - 1;

    x = first_x;
    while(x < last_x)
    {
        sp_texx = (int)(256 * (x- (-spritewidth / 2 + spritescreenx)) * mlx->sprite[i].tex.img_widht / spritewidth / 256);
        y = first_y;
        if (transformy > 0 && x > 0 && x < mlx->config->resolutionwidht &&
			transformy < mlx->sprite_buff[x])
            while (y < last_y)
			{
				sp_texy = ((((y) * 256 - mlx->config->resolutionheight * 128 + spriteheight * 128) *
				mlx->sprite[i].tex.img_height) / spriteheight) / 256;
				if (mlx->sprite[i].tex.img_addr[4 * (sp_texx + 64 * sp_texy)]
				!= (char)0)
					ft_memcpy(mlx->img_addr + 4 * mlx->config->resolutionwidht * y + x * 4,
						&mlx->sprite[i].tex.img_addr[sp_texy % mlx->sprite[i].tex.img_height *
						mlx->sprite[i].tex.line_lenght + sp_texx % mlx->sprite[i].tex.img_widht
						* mlx->sprite[i].tex.bpp / 8], sizeof(int));
				y++;
			}
        x++;
    }
    i++;
    }
    //printf("%d\n", mlx->tex[4].img_height);
    return;
}