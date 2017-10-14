/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:06:20 by ederbano          #+#    #+#             */
/*   Updated: 2017/10/25 15:54:58 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_is_command(char *str)
{
	if (!str || !*str)
		ft_err();
	if (ft_strcmp(str, "##start") == 0)
		return (1);
	if (ft_strcmp(str, "##end") == 0)
		return (2);
	return (0);
}

int	ft_is_comment(char *str)
{
	if (!str || !*str)
		ft_err();
	if (str[0] != '#')
		return (0);
	if (ft_is_command(str) != 0)
		return (0);
	return (1);
}

int	ft_is_ants(char *str)
{
	int i;

	if (!str || !*str)
		ft_err();
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_link(char *str)
{
	int i;
	int dash;

	if (!str || !*str)
		ft_err();
	if (ft_is_ants(str) || ft_is_comment(str) || ft_is_command(str))
		return (0);
	i = 0;
	dash = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			return (0);
		if (str[i] == '-')
			dash++;
		i++;
	}
	if (dash < 1)
		ft_err();
	return (1);
}

int	ft_is_room(char *str)
{
	if (!str || !*str)
		ft_err();
	if (ft_is_comment(str) || ft_is_ants(str) || ft_is_link(str)
			|| ft_is_command(str))
		return (0);
	return (1);
}
