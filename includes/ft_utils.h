/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <mviudes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:21:33 by mviudes           #+#    #+#             */
/*   Updated: 2020/07/31 11:08:24 by mviudes          ###   ########.fr       */
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

/*borrar al entregar*/
int			print_map(t_config *config);
#endif
