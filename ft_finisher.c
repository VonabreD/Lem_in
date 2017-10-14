/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finisher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 13:23:11 by ederbano          #+#    #+#             */
/*   Updated: 2017/10/14 13:23:14 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_room_help(int *dist, t_links *ln, t_names *ns)
{
	if (*dist > (ft_fn(ln->name2, ns))->dist
		&& (ft_fn(ln->name2, ns))->dist >= 0
		&& (ft_fn(ln->name2, ns))->used == 0)
		return (1);
	if (*dist > (ft_fn(ln->name1, ns))->dist
		&& (ft_fn(ln->name1, ns))->dist >= 0
		&& (ft_fn(ln->name1, ns))->used == 0)
		return (2);
	return (0);
}

t_way	*ft_next_room(t_names *ns, t_links *ln, t_way *way)
{
	char	*nt_rm;
	int		dist;
	t_way	*nt_way;

	dist = INT_MAX;
	nt_rm = "";
	while (ln != NULL)
	{
		if (ft_strcmp(way->name, ln->name1) == 0)
			if (ft_room_help(&dist, ln, ns) == 1)
			{
				nt_rm = ln->name2;
				dist = (ft_name_find(ln->name2, ns))->dist;
			}
		if (ft_strcmp(way->name, ln->name2) == 0)
			if (ft_room_help(&dist, ln, ns) == 2)
			{
				nt_rm = ln->name1;
				dist = (ft_name_find(ln->name1, ns))->dist;
			}
		ln = ln->next;
	}
	nt_way = ft_way_init(nt_rm);
	return (nt_way);
}

int		ft_is_end(t_way *way, char *str)
{
	if (ft_strcmp(way->name, str) == 0)
		return (0);
	return (1);
}

int		ft_take_ants(char **data)
{
	int i;

	i = 0;
	if (!data || data[0] == NULL)
		ft_err();
	while (ft_is_comment(data[i]) == 1)
		i++;
	if (ft_is_ants(data[i]) == 0)
		ft_err();
	return (ft_mod_atoi(data[i]));
}

void	ft_chk_finit(t_tub **tub, char *str)
{
	int		i;
	t_way	*line;

	i = 0;
	while ((*tub)[i].finit != -666)
	{
		(*tub)[i].len = 0;
		line = (*tub)[i].way;
		(*tub)[i].finit = 0;
		while (line != NULL)
		{
			(*tub)[i].len += 1;
			if (ft_strcmp(line->name, str) == 0)
				(*tub)[i].finit = 1;
			line = line->next;
		}
		i++;
	}
}
