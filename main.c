/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 13:42:14 by ederbano          #+#    #+#             */
/*   Updated: 2017/10/14 13:42:16 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_links_test_2(t_links *links)
{
	int		i;
	t_links	*tmp;
	t_links	*start;

	tmp = links;
	start = links;
	while (tmp != NULL)
	{
		i = 0;
		links = start;
		while (links != NULL)
		{
			if (ft_strcmp(links->name1, tmp->name1) == 0
				&& ft_strcmp(links->name2, tmp->name2) == 0)
				i++;
			links = links->next;
		}
		if (i > 1)
			ft_err();
		tmp = tmp->next;
	}
}

int		main(void)
{
	char	**data_in;
	t_links	*links;
	t_names	*names;
	t_tub	*tubs;

	data_in = ft_parse(0);
	ft_take_ants(data_in);
	ft_commands(data_in);
	names = ft_take_names(data_in);
	ft_chk_names(names);
	links = ft_take_links(data_in, names);
	ft_links_test_2(links);
	ft_brain(names, links);
	tubs = ft_tub_make(names, links);
	ft_chk_finit(&tubs, ft_find_lst_name(names));
	ft_sort_ways(&tubs);
	ft_print_ways(ft_take_ants(data_in), tubs, data_in);
	return (0);
}
