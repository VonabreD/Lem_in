/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:37:09 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 15:56:05 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	size_t	i;

	if (!s || !f)
		return (0);
	i = -1;
	if (!(ptr = (char *)malloc(ft_strlen(s) + 1)))
		return (0);
	while (++i < ft_strlen(s))
		ptr[i] = f((char)s[i]);
	ptr[i] = '\0';
	return (ptr);
}
