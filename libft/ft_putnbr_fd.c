/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:43:54 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 16:03:36 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int i, int fd)
{
	char		c;
	long int	x;

	x = (long int)i;
	if (x < 0)
	{
		ft_putchar_fd('-', fd);
		x *= -1;
	}
	if (x >= 0)
	{
		c = x % 10 + 48;
		if (x / 10 > 0)
			ft_putnbr_fd(x / 10, fd);
		ft_putchar_fd(c, fd);
	}
}
