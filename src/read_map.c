/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 13:15:12 by mviudes           #+#    #+#             */
/*   Updated: 2020/12/18 11:13:15 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <read_map.h>
#include <ft_utils.h>

int		get_size_map(t_config *config, char *line)
{
	int i; 

	i = 1;
	config->map.max_height++;
	while (((line[i] >= 48 && line[i] <= 57) || line[i] == ' ' ||
			line[i] == 'N' || line[i] == 'S' || line[i] == 'W' ||
			line[i] == 'E') &&
			line[i])
		i++;
	if (i > config->map.max_widht)
		config->map.max_widht = i;
	return 1;
}

int				read_map(t_config *config, char *line)
{
	config->flags.readingmap = 1;
	get_size_map(config, line);
	copy_map(config, line);
	if (config->lastline == 0)
	{
		allocate_map(config);
		fill_map(config);
		get_sprites(config);
	}
	return (0);
}



void		allocate_map(t_config  *config)
{
	int		i;

	i = 0;
	config->map.map = ft_calloc(sizeof(int*), config->map.max_height);
	while (i < config->map.max_height)
	{
		config->map.map[i] = ft_calloc(sizeof(int), config->map.max_widht);
		i++;
	}
}

void		get_init_position(t_config *config, int widht, int height)
{
	config->init_pos.x = height;
	config->init_pos.y = widht;
	config->flags.initpos += 1;
}

int			copy_map(t_config *config, char *line)
{
	t_lstbuff	*tmp;
	char 		*newstr;

	newstr = ft_strdup(line);
	tmp = ft_lstbuff_new(newstr);
	ft_lstbuffadd_back(&(config->map.buff),tmp);
	return (0);
}

t_lstbuff	*ft_lstbuff_new(char const *content)
{
	t_lstbuff	*new;

	if (!(new = (t_lstbuff*)malloc(sizeof(content))))
		return (NULL);
	new->line = (char *)content;
	new->next = NULL;
	return (new);
}

void		ft_lstbuffadd_back(t_lstbuff **lst, t_lstbuff *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstbufflast(*lst)->next = new;
}

t_lstbuff	*ft_lstbufflast(t_lstbuff *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
char 		*ft_lstpop_first(t_lstbuff **lst)
{
	char *string;
    t_lstbuff *next;
	
	next = NULL;
    if (*lst == NULL) {
        return NULL;
    }
    next = (*lst)->next;
    string = (*lst)->line;
    free(*lst);
    *lst = next;
    return (string);
}

int			fill_map(t_config *config)
{
	int		row;
	int		column;
	char	*temp;
	int		i;
	int		j;
	int		firstwhitespaces;

	row = 0;
	temp = 0;
	map_fill_with(config, '4');
	while(row < config->map.max_height)
	{
		temp = ft_lstpop_first(&config->map.buff);
		i = 0;
		while(temp[i] != '\0')
			{
				if(ft_iswhitespace(temp[i]))
						config->map.map[row][i] = 4;
				else if (ft_isdigit(temp[i]))
					config->map.map[row][i] = temp[i] - '0';
				else if (ft_isascii(temp[i]))
				{	
					config->init_dir = temp[i];
					get_init_position(config, i, row);
					config->map.map[row][i] = 0;
				}
				else 
					config->map.map[row][i] = 4;
				i++;		
			}
		j++;
		row++;
		free(temp);
		temp = NULL;
	}
	return(0);
}

int			map_fill_with(t_config *config, char c)
{
	int j;
	int i;

	j = 0;
	while (j < config->map.max_height)
	{
		i = 0;
		while (i < config->map.max_widht)
			{
				config->map.map[j][i] = c - '0';
				i++;
			}
		j++;
	}
	return (0);
}

int			check_map_walls(t_config *config)
{
	int i;
	int j;
	int width;
	int heigh;
	int temp;

	i = 1;
	j = 1;
	width = config->map.max_widht - 1;
	heigh = config->map.max_height -1;

	while (j < heigh)
	{
		while (i < width)
			{
				if (config->map.map[j][i] == 0 ||
					config->map.map[j][i] == 2)
				{
					if (config->map.map[j+1][i] == 4)
					{
						error_exit("mapa abierto");
					}
					if (config->map.map[j][i+1] == 4)
					{
						error_exit("mapa abierto");
					}
					if (config->map.map[j-1][i] == 4)
					{
						error_exit("mapa abierto");
					}
					if (config->map.map[j][i-1] == 4)
					{
						error_exit("mapa abierto");
					}
				}
				i++;
			}
		j++;
		i = 0;
	}
	i = 0;
	j = 0;
	while (i < width)
	{
		if(config->map.map[0][i] != 1)
			if(config->map.map[0][i] != 4)
				error_exit("mapa abierto");
		if(config->map.map[heigh][i] != 1)
			if(config->map.map[heigh][i] != 4)
				error_exit("mapa abierto");
		i++;
	}
	while (j < heigh)
	{
		if(config->map.map[j][0] != 1)
			if(config->map.map[j][0] != 4)
				error_exit("mapa abierto");
		if(config->map.map[j][width] != 1)
			if(config->map.map[j][width] != 4)
				error_exit("mapa abierto");
		j++;
	}
	return (0);
}
void		get_sprites(t_config *config)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	j = 0;
	while (j < config->map.max_height)
	{
		i = 0;
		while (i < config->map.max_widht){
			if(config->map.map[j][i] == 2)
				config->spritecount++;
			i++;
		}
		j++;
	}
	free(config->sprite);
	if(!(config->sprite = (t_sprite*)malloc(sizeof (t_sprite) * config->spritecount - 1)))
		return;
	j = 0;
	while (j < config->map.max_height)
	{
		i = 0;
		while (i < config->map.max_widht){
			if(config->map.map[j][i] == 2 && k < config->spritecount){
				config->sprite[k].x = j + 0.5;
				config->sprite[k].y = i + 0.5;
				config->sprite[k].id = k;
				k++;
			}
			i++;
		}
		j++;
	}
}