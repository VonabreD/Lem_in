/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:40:58 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/07 17:02:21 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int ch)
{
	if ((ch > 47 && ch < 58) || (ch > 64 && ch < 91) || (ch > 96 && ch < 123))
		return (1);
	return (0);
}
