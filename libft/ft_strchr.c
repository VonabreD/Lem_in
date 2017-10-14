/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:51:26 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 10:20:56 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = -1;
	ptr = (char *)s;
	while (ptr[++i])
		if (ptr[i] == c)
			return (&ptr[i]);
	if (ptr[i] == c)
		return (&ptr[i]);
	return (0);
}
