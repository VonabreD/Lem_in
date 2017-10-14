/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:04:07 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 09:40:42 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	while (num--)
		*cdst++ = *csrc++;
	return (dest);
}
