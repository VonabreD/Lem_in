/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:18:48 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/07 18:41:20 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_count(unsigned long int num)
{
	int count;

	count = 0;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static void	ft_pull(unsigned long int n1, int i, int t, char *str)
{
	str[i] = '\0';
	while (i > t)
	{
		str[i - 1] = (n1 % 10) + 48;
		n1 = n1 / 10;
		i--;
	}
	if (t == 1)
		str[0] = 45;
}

char		*ft_itoa(int n)
{
	int						i;
	int						t;
	char					*str;
	unsigned long int		n1;

	i = 0;
	t = 0;
	if (n < 0)
	{
		n1 = (unsigned long int)n * (-1) + 0 * i++;
		t = 1;
	}
	else
		n1 = (unsigned long int)n;
	if (n == 0)
		i++;
	i = i + ft_count(n1);
	if (!(str = ft_strnew((size_t)i)))
		return (NULL);
	ft_pull(n1, i, t, str);
	return (str);
}
