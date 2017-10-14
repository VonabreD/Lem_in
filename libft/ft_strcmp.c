/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:58:04 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 10:30:18 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *a, const char *b)
{
	unsigned char *aa;
	unsigned char *bb;

	aa = (unsigned char *)a;
	bb = (unsigned char *)b;
	while (*aa && *bb && *aa == *bb)
	{
		aa++;
		bb++;
	}
	return ((int)(*aa - *bb));
}
