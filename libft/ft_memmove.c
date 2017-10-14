/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:08:09 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 16:10:10 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	const char	*csrc;
	size_t		i;

	cdst = (char *)dst;
	csrc = (const char *)src;
	i = -1;
	if (cdst < csrc)
		while (++i < len)
			cdst[i] = csrc[i];
	else
		while (len--)
			cdst[len] = csrc[len];
	return (dst);
}
