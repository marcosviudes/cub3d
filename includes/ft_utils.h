/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:21:33 by mviudes           #+#    #+#             */
/*   Updated: 2020/10/07 16:58:25 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_iswhitespace(int c);
char		**ft_getsubstrings(char *string);
int			ft_strisnum(char *string);
int			ft_cmpstr(char *string1, char *string2);
int			find_char_str(char c, char const *string);
void        ft_remchar(char *string, char c);
/*pruebas*/

t_lstbuff *ft_lstbuff_new(char const *content);
void		ft_lstbuffadd_back(t_lstbuff **lst, t_lstbuff *new);
t_lstbuff	*ft_lstbufflast(t_lstbuff *lst);
char		*ft_lstpop_first(t_lstbuff **lst);
/*borrar al entregar*/
int			print_map(t_config *config);
int		print_sprites(t_config *config);

void		ft_nullfree(void *ptr);

#endif
