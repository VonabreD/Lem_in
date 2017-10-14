/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:29:24 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 10:10:40 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char	*ptr;
	int		i;

	if (!s)
		return ;
	i = -1;
	ptr = (char *)s;
	while (ptr[++i])
		ft_putchar_fd(ptr[i], fd);
}
