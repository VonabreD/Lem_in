/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:23:06 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 10:18:28 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *s)
{
	size_t i;
	size_t k;
	size_t j;

	i = ft_strlen(dest);
	k = ft_strlen(s);
	j = 0;
	while (j < k)
		dest[i++] = s[j++];
	dest[i] = '\0';
	return (dest);
}
