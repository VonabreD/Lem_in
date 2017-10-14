/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:22:11 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/07 19:30:03 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c,
		size_t num)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	size_t			i;

	i = 0;
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	while (i < num)
	{
		cdest[i] = csrc[i];
		dest++;
		if (csrc[i] == (unsigned char)c)
			return (dest);
		i++;
	}
	return (0);
}
