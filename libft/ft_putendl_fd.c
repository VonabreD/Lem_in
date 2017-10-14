/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:36:59 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 10:14:27 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char	*ptr;
	int		i;

	if (!s)
		return ;
	i = -1;
	ptr = (char *)s;
	while (ptr[++i])
		ft_putchar_fd(ptr[i], fd);
	ft_putchar_fd('\n', fd);
}
