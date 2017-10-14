/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:09:10 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 14:38:29 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s || !(ptr = (char *)malloc(len + 1)))
		return (0);
	while (i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
