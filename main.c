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

int	main(void)
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
	ft_brain(names, links);
	tubs = ft_tub_make(names, links);
	ft_chk_finit(&tubs, ft_find_lst_name(names));
	ft_sort_ways(&tubs);
	ft_print_ways(ft_take_ants(data_in), tubs, data_in);
	return (0);
}
