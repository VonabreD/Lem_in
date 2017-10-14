/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:44:35 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 16:55:08 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	int *rng;
	int i;

	i = 0;
	if (min >= max)
		return (NULL);
	rng = (int *)malloc(sizeof(int) * (max + 1 - min));
	while (min < max)
	{
		rng[i] = min++;
		i++;
	}
	rng[i] = 0;
	return (rng);
}
