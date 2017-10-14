/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextwrd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:07:34 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 16:11:10 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_nextwrd(char **tab, size_t i, char const *s, char c)
{
	char	*str;
	size_t	len;
	size_t	j;

	while (*s == c)
		s++;
	str = (char*)s;
	while (*str && *str != c)
		str++;
	len = str - s;
	tab[i] = (char*)malloc(sizeof(*str) * (len + 1));
	j = 0;
	while (*s != '\0' && *s != c)
		tab[i][j++] = *(s++);
	tab[i][j] = '\0';
	return (s);
}
