/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 20:01:41 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 15:58:04 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	int i;

	i = -1;
	while (src[++i] && len)
	{
		dest[i] = src[i];
		len--;
	}
	while (len--)
		dest[i++] = '\0';
	return (dest);
}
