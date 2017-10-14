/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 20:41:33 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 10:53:55 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *ptr;

	if (!(ptr = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	return (ft_strcpy(ptr, s));
}
