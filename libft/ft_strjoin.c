/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:33:11 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 16:06:29 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (*s1)
		ptr[i++] = *s1++;
	while (*s2)
		ptr[i++] = *s2++;
	ptr[len] = '\0';
	return (ptr);
}
