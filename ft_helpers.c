/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 13:05:14 by ederbano          #+#    #+#             */
/*   Updated: 2017/10/14 13:05:17 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_command_help(int *c, char *str)
{
	*c = *c + 1;
	if (ft_is_room(str) == 0)
		ft_err();
}

void	ft_commands(char **data)
{
	int i;
	int st;
	int end;

	st = 0;
	end = 0;
	i = -1;
	while (data[++i] != NULL)
	{
		if (ft_strcmp(data[i], "##start") == 0)
			ft_command_help(&st, data[++i]);
		if (ft_strcmp(data[i], "##end") == 0)
			ft_command_help(&end, data[++i]);
	}
	if (st != 1 && end != 1)
		ft_err();
}

int		ft_mod_atoi(const char *str)
{
	unsigned long int	n;
	int					minus;

	minus = 1;
	n = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r' ||
			*str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = 44 - *str++;
		if (*str == '+' && minus != -1)
			str++;
	}
	while (*str >= '0' && *str <= '9')
		n = (*str++ - 48) + (n * 10);
	if ((n >= 2147483648 && minus == 1) || (n >= 2147483647 && minus == 0))
		ft_err();
	return ((int)(n * minus));
}

int		ft_num_lnk(t_links *links, char *name)
{
	int i;

	i = 0;
	while (links != NULL)
	{
		if (ft_strcmp(links->name1, name) == 0)
			i++;
		if (ft_strcmp(links->name2, name) == 0)
			i++;
		links = links->next;
	}
	return (i);
}

int		ft_num_ways(t_names *names, t_links *links)
{
	int i;
	int j;

	i = ft_num_lnk(links, ft_find_fst_name(names));
	j = ft_num_lnk(links, ft_find_lst_name(names));
	if (i > j)
		return (j);
	return (i);
}
