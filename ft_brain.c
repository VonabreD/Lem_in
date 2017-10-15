/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 13:10:07 by ederbano          #+#    #+#             */
/*   Updated: 2017/10/14 13:10:11 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_links_test(char *str, t_names *names)
{
	t_names	*nam_ptr;
	int		i;

	i = 0;
	nam_ptr = names;
	while (nam_ptr != NULL)
	{
		if (ft_strcmp(nam_ptr->name, str) == 0)
			i++;
		nam_ptr = nam_ptr->next;
	}
	if (i == 0)
		ft_err();
}

void	ft_brain_help(t_que **que, t_names *ns, t_links *ln)
{
	t_names *e;

	if (ft_strcmp(que[0]->elem->name, ln->name1) == 0)
	{
		e = ft_fn(ln->name2, ns);
		if (e->dist == -1)
		{
			e->dist = que[0]->elem->dist + 2;
			ft_push_queue(que[1], e);
		}
	}
	if (ft_strcmp(que[0]->elem->name, ln->name2) == 0)
	{
		e = ft_fn(ln->name1, ns);
		if (e->dist == -1)
		{
			e->dist = que[0]->elem->dist + 2;
			ft_push_queue(que[1], e);
		}
	}
}

void	ft_brain(t_names *names, t_links *links)
{
	int		status;
	t_links	*lnk;
	t_que	*queue[2];

	status = 1;
	queue[0] = ft_queue_init(names);
	queue[1] = queue[0];
	while (status && queue[0] != NULL)
	{
		lnk = links;
		while (lnk != NULL)
		{
			ft_brain_help(queue, names, lnk);
			lnk = lnk->next;
		}
		queue[0] = queue[0]->next;
		status = ft_chk_dist(names);
	}
	ft_free_que(queue[1]);
}

t_way	*ft_find_way(t_names *names, t_links *links)
{
	t_way	*way;
	t_way	*s_way;
	int		status;

	way = ft_way_init(ft_find_fst_name(names));
	s_way = way;
	status = 1;
	while (status)
	{
		way->ant = 0;
		way->next = ft_next_room(names, links, way);
		way = way->next;
		status = ft_is_end(way, ft_find_lst_name(names));
		if (way->name[0] == '\0')
			status = 0;
	}
	return (s_way);
}

t_tub	*ft_tub_make(t_names *names, t_links *links)
{
	t_tub	*tub;
	int		i;
	int		j;

	i = ft_num_ways(names, links);
	tub = (t_tub *)malloc(sizeof(t_tub) * (i + 1));
	j = -1;
	tub[i].finit = -666;
	while (++j < i)
		tub[j].way = ft_find_way(names, links);
	return (tub);
}
