/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprosian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:50:06 by sprosian          #+#    #+#             */
/*   Updated: 2017/01/10 18:07:12 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_bcnt(char const *s)
{
	int		j;

	j = (int)ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	return (j);
}

char			*ft_strtrim(char const *s)
{
	char	*ptr;
	int		i;
	int		k;
	int		q;
	int		j;

	if (s == NULL)
		return (0);
	k = 0;
	q = ft_cnt(s);
	j = ft_bcnt(s);
	i = q + (ft_strlen(s) - 1 - j);
	if (i > (int)ft_strlen(s))
		i = q;
	if (i == (int)ft_strlen(s))
		return (ft_strnew(0));
	ptr = (char *)malloc((int)ft_strlen(s) - i + 1);
	if (ptr == NULL)
		return (0);
	while (q != j + 1)
		ptr[k++] = s[q++];
	ptr[k] = '\0';
	return (ptr);
}
