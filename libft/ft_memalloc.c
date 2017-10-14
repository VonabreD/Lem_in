/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:45:08 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 09:24:32 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;

	if (!size)
		return (NULL);
	if (!(ptr = (char*)malloc(size)))
		return (NULL);
	ft_bzero(ptr, size);
	return ((void *)ptr);
}
