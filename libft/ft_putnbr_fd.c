/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviudes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:44:42 by mviudes           #+#    #+#             */
/*   Updated: 2019/11/23 18:31:51 by mviudes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n < 10)
	{
		ft_putchar_fd((n + '0'), fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10 + '0'), fd);
	}
	else if (n > -10)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd((n * -1 + '0'), fd);
	}
	else
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd((-1 * (n / 10)), fd);
		ft_putchar_fd((-1 * (n % 10) + '0'), fd);
	}
}
