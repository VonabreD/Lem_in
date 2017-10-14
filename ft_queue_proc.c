/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_proc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 13:08:43 by ederbano          #+#    #+#             */
/*   Updated: 2017/10/14 13:08:45 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_que	*ft_queue_init(t_names *names)
{
	t_que *queue;

	while (names != NULL)
	{
		if (names->pos == 2)
			break ;
		names = names->next;
	}
	queue = (t_que *)malloc(sizeof(t_que));
	queue->elem = names;
	queue->next = NULL;
	return (queue);
}

t_names	*ft_fn(char *str, t_names *names)
{
	while (names != NULL)
	{
		if (ft_strcmp(str, names->name) == 0)
			return (names);
		names = names->next;
	}
	return (NULL);
}

void	ft_push_queue(t_que *queue, t_names *elem)
{
	while (queue->next != NULL)
		queue = queue->next;
	queue->next = (t_que *)malloc(sizeof(t_que));
	queue = queue->next;
	queue->elem = elem;
	queue->next = NULL;
}

int		ft_chk_dist(t_names *names)
{
	int i;

	i = 0;
	while (names != NULL)
	{
		if (names->dist == -1)
			i++;
		names = names->next;
	}
	if (i == 0)
		return (0);
	return (1);
}

void	ft_free_que(t_que *queue)
{
	t_que *tmp;

	while (queue != NULL)
	{
		tmp = queue->next;
		free(queue);
		queue = tmp;
	}
}
