/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_names.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 12:59:00 by ederbano          #+#    #+#             */
/*   Updated: 2017/10/14 12:59:04 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_names	*ft_add_name(void)
{
	t_names *new_name;

	new_name = (t_names*)malloc(sizeof(t_names));
	new_name->name = "";
	new_name->next = NULL;
	new_name->pos = 0;
	return (new_name);
}

void	ft_chk_names(t_names *names)
{
	t_names *start;
	t_names *tmp;

	start = names;
	while (names != NULL)
	{
		if (names->name[0] == 'L' || names->name[0] == '#')
			ft_err();
		names = names->next;
	}
	names = start;
	while (names != NULL)
	{
		tmp = names->next;
		while (tmp != NULL)
		{
			if (ft_strcmp(names->name, tmp->name) == 0 ||
				(names->x == tmp->x && names->y == tmp->y))
				ft_err();
			tmp = tmp->next;
		}
		names = names->next;
	}
}

char	*ft_find_fst_name(t_names *names)
{
	while (names != NULL)
	{
		if (names->pos == 1)
			return (names->name);
		names = names->next;
	}
	return (NULL);
}

char	*ft_find_lst_name(t_names *names)
{
	while (names != NULL)
	{
		if (names->pos == 2)
			return (names->name);
		names = names->next;
	}
	return (NULL);
}

t_names	*ft_name_find(char *str, t_names *names)
{
	while (names != NULL)
	{
		if (ft_strcmp(str, names->name) == 0)
		{
			if (names->pos != 2)
				names->used = 1;
			return (names);
		}
		names = names->next;
	}
	return (NULL);
}
