/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:06:49 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 16:09:48 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (1);
	if (ft_strlen((char *)s1) != ft_strlen((char *)s2))
		return (0);
	while (*s1)
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (0);
	return (1);
}
