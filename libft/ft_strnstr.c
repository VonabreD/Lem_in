/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:17:13 by sprosian          #+#    #+#             */
/*   Updated: 2017/01/09 18:10:43 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*ss1;
	char	*ss2;
	int		fl;
	int		i;

	i = 0;
	while (*s1 && (i++ < ((int)(len - ft_strlen(s2) + 1))))
	{
		fl = 1;
		ss1 = (char *)s1;
		ss2 = (char *)s2;
		while (*ss2)
		{
			if (*ss2++ != *ss1++)
				fl = 0;
		}
		if (fl == 1)
			return ((char *)s1);
		s1++;
	}
	return (0);
}
