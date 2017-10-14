/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:08:48 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 16:04:36 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	words;
	char	**tab;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	words = ft_nbwrd(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	while (i < words)
		s = ft_nextwrd(tab, i++, s, c);
	tab[i] = NULL;
	return (tab);
}
