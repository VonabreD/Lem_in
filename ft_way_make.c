/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 13:39:16 by ederbano          #+#    #+#             */
/*   Updated: 2017/10/14 13:39:18 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_way	*ft_way_init(char *str)
{
	t_way *way;

	if (str == NULL)
		return (NULL);
	way = (t_way *)malloc(sizeof(t_way));
	way->name = ft_strjoin("", str);
	way->next = NULL;
	return (way);
}

void	ft_sort_ways(t_tub **tub)
{
	int		i;
	int		j;
	t_tub	tmp;

	j = -1;
	while ((*tub)[++j].finit != -666)
	{
		i = j - 1;
		tmp.way = (*tub)[j].way;
		tmp.len = (*tub)[j].len;
		tmp.finit = (*tub)[j].finit;
		while ((*tub)[i++].finit != -666)
			if ((*tub)[i].len < (*tub)[j].len && (*tub)[i].finit == 1)
			{
				(*tub)[j].way = (*tub)[i].way;
				(*tub)[j].len = (*tub)[i].len;
				(*tub)[j].finit = (*tub)[i].finit;
				(*tub)[i].way = tmp.way;
				(*tub)[i].len = tmp.len;
				(*tub)[i].finit = tmp.finit;
			}
	}
}

int		ft_count_ways(t_tub *tub, int ants)
{
	int i;
	int j;
	int len;

	i = -1;
	j = 0;
	len = 0;
	if (tub[0].len == 2)
		return (1);
	while (tub[++i].finit != -666)
	{
		if (tub[i].finit == 1 && len < ants)
		{
			len += tub[i].len;
			j++;
		}
	}
	if (j == 0)
		ft_err();
	return (j);
}

int		ft_fill_rooms(t_tub *tub, int n_a)
{
	t_way *tmp;

	if (tub->finit == 0)
		return (0);
	tmp = tub->way->end;
	while (tmp->pre->pre != NULL)
	{
		tmp->ant = tmp->pre->ant;
		tmp = tmp->pre;
	}
	tub->way->next->ant = n_a;
	return (1);
}

void	ft_pre_ways(t_tub *tub)
{
	t_way	*tmp;
	t_way	*ptr;
	t_way	*tmp2;
	int		i;

	i = -1;
	while (tub[++i].finit != -666)
	{
		ptr = tub[i].way;
		while (ptr->next != NULL)
			ptr = ptr->next;
		tmp2 = tub[i].way;
		tmp = NULL;
		tmp2->pre = NULL;
		while (tmp2 != NULL)
		{
			tmp2->pre = tmp;
			tmp2->end = ptr;
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
	}
}
