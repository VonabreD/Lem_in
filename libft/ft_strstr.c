/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:28:56 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 14:31:01 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str1, const char *str2)
{
	char	*ptr;
	char	*ptr1;
	int		ch;

	if (ft_strlen(str2) == 0)
		return ((char *)str1);
	while (*str1)
	{
		ch = 0;
		ptr = (char *)str1;
		ptr1 = (char *)str2;
		while (*ptr1)
			if (*ptr++ != *ptr1++)
				ch = 1;
		if (ch == 0)
			return ((char *)str1);
		str1++;
	}
	return (0);
}
