/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:54:27 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 17:56:03 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *a, const char *b, size_t n)
{
	unsigned char	*aa;
	unsigned char	*bb;

	aa = (unsigned char *)a;
	bb = (unsigned char *)b;
	while (*aa && *bb && n > 0)
	{
		if (*aa != *bb)
			return ((int)(*aa - *bb));
		aa++;
		bb++;
		n--;
	}
	if (*aa != *bb && n > 0)
		return ((int)(*aa - *bb));
	return (0);
}
