/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 12:56:12 by ederbano          #+#    #+#             */
/*   Updated: 2017/10/14 12:56:23 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_data(char **data)
{
	int i;
	int j;

	j = 0;
	write(1, "\033[0;33m)", 7);
	while (data[j] != NULL)
	{
		i = 0;
		while (data[j][i] != '\0')
			write(1, &data[j][i++], 1);
		write(1, "\n", 1);
		j++;
	}
	write(1, "\033[0m\n", 5);
}

void	ft_print_ways(int ants, t_tub *tub, char **data_in)
{
	int num;
	int i;
	int j;
	int flag;

	num = ft_count_ways(tub, ants);
	ft_print_data(data_in);
	ft_pre_ways(tub);
	i = 1;
	flag = 1;
	while (1)
	{
		j = -1;
		while (++j != num)
		{
			if (i > ants || flag < 1)
				i = 0 * flag--;
			i += ft_fill_rooms(&tub[j], i);
		}
		if (ft_print_step(tub) < 1)
			break ;
	}
}

int		ft_print_step(t_tub *tub)
{
	int		i[2];
	t_way	*tmp;

	i[1] = 0;
	i[0] = -1;
	while (tub[++i[0]].finit != -666)
	{
		tmp = tub[i[0]].way->end;
		while (tmp != NULL)
		{
			if (tmp->ant > 0)
			{
				write(1, "\033[1;35mL", 8);
				ft_putnbr(tmp->ant);
				write(1, "-", 1);
				ft_putstr(tmp->name);
				write(1, " ", 1);
				i[1]++;
			}
			tmp = tmp->pre;
		}
	}
	write(1, "\n", 1);
	return (i[1]);
}

int		ft_err(void)
{
	write(1, "\033[1;31m)", 7);
	write(1, "ERROR\n", 6);
	exit(1);
}
