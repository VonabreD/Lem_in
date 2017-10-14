/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:23:55 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 11:37:00 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int			i;
	size_t		j;
	size_t		tm;
	size_t		rez;

	i = -1;
	j = ft_strlen(dest);
	rez = j + ft_strlen(src);
	tm = size - j;
	if (j < size)
	{
		while (src[++i] && --tm)
			dest[j++] = src[i];
		dest[j] = '\0';
		return (rez);
	}
	return (size + ft_strlen(src));
}
