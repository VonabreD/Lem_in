/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:45:54 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 10:12:53 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	char	*ptr;
	int		i;

	if (!s)
		return ;
	i = -1;
	ptr = (char *)s;
	while (ptr[++i])
		ft_putchar(ptr[i]);
	ft_putchar('\n');
}
