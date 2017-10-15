/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 14:06:20 by ederbano          #+#    #+#             */
/*   Updated: 2017/10/25 15:54:58 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_first_wrd(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	tmp = ft_strncpy(tmp, str, (size_t)i);
	tmp[i] = '\0';
	return (tmp);
}

int		ft_take_y(char *str)
{
	int i;
	int y;
	int j;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	i++;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	j = ++i;
	if (str[j] == '-')
		j++;
	while (str[j] != '\0')
		if (ft_isdigit(str[j++]) == 0)
			ft_err();
	if (str[i] == '\0' || str[i] == ' ')
		ft_err();
	y = ft_mod_atoi(&str[i]);
	return (y);
}

int		ft_take_x(char *str)
{
	int i;
	int j;
	int x;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	j = ++i;
	if (str[j] == '-')
		j++;
	while (str[j] != '\0' && str[j] != ' ')
		if (ft_isdigit(str[j++]) == 0)
			ft_err();
	if (str[i] == '\0' || str[i] == ' ')
		ft_err();
	x = ft_mod_atoi(&str[i]);
	return (x);
}

void	ft_init_names(t_names **start, t_names **names, char **data, int *i)
{
	if (*names == NULL)
	{
		*names = ft_add_name();
		*start = *names;
	}
	else
	{
		(*names)->next = ft_add_name();
		*names = (*names)->next;
	}
	(*names)->name = ft_first_wrd(data[i[0]]);
	(*names)->pos = ft_is_command(data[i[0] - 1]);
	if ((*names)->pos == 2)
		(*names)->dist = 0;
	else if ((*names)->pos == 1)
		(*names)->dist = INT_MAX;
	else
		(*names)->dist = -1;
	(*names)->x = ft_take_x(data[i[0]]);
	(*names)->y = ft_take_y(data[i[0]]);
	(*names)->used = 0;
}

t_names	*ft_take_names(char **data)
{
	int		i[2];
	t_names	*names;
	t_names	*start_lst;

	i[0] = 0;
	i[1] = 0;
	names = NULL;
	start_lst = NULL;
	while (data[i[0]] != NULL && ft_is_room(data[i[0]]) == 0)
		i[0]++;
	if (data[i[0]] == NULL)
		ft_err();
	while (data[i[0]] != NULL && (ft_is_room(data[i[0]])
						|| ft_is_command(data[i[0]])
						|| ft_is_comment(data[i[0]])))
	{
		if (ft_is_room(data[i[0]]))
			ft_init_names(&start_lst, &names, data, i);
		i[0]++;
	}
	return (start_lst);
}
