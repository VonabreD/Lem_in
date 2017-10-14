/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:10:03 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 12:18:51 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t			i;
	char			*ptr;

	ptr = (char *)s1;
	i = ft_strlen(ptr);
	while (n-- && *s2 != '\0')
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}
