/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poc_in_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 12:57:34 by ederbano          #+#    #+#             */
/*   Updated: 2017/10/14 12:57:39 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**ft_parse(int fd)
{
	char	*line[3];
	char	**data;
	int		i;

	i = 0;
	line[0] = "";
	line[2] = "";
	while (get_next_line(fd, &line[2]) > 0)
	{
		if (line[2][0] == '\0')
			break ;
		line[1] = ft_strjoin(line[0], line[2]);
		if (*(line[0]) != '\0')
			free(line[0]);
		line[0] = ft_strjoin(line[1], "\n");
		free(line[1]);
		free(line[2]);
		i++;
	}
	if (line[0][0] == '\0')
		ft_err();
	data = ft_strsplit(line[0], '\n');
	free(line[0]);
	return (data);
}

void	ft_init_links(t_links **links, t_links **start)
{
	if (*links == NULL)
	{
		*links = (t_links *)malloc(sizeof(t_links));
		(*links)->next = NULL;
		*start = *links;
	}
	else
	{
		(*links)->next = (t_links *)malloc(sizeof(t_links));
		*links = (*links)->next;
		(*links)->next = NULL;
	}
}

void	ft_links_help(char **d, t_names *n, int i, t_links **l)
{
	int		ig;
	t_names	*ptr;

	ig = 0;
	if (n == NULL)
		ig++;
	ptr = n;
	while (n != NULL)
	{
		if (d[i][ft_strlen(n->name)] == '-' && ft_strcmp(n->name, d[i]) == -45)
		{
			ft_init_links(&l[0], &l[1]);
			l[0]->name1 = ft_strjoin("", n->name);
			l[0]->name2 = ft_strjoin("", &d[i][ft_strlen(n->name) + 1]);
			ft_links_test(l[0]->name2, ptr);
			ig++;
		}
		n = n->next;
	}
	if (ig == 0)
		ft_err();
}

t_links	*ft_take_links(char **data, t_names *names)
{
	int		i;
	t_links	*links[2];

	i = 0;
	links[0] = NULL;
	links[1] = NULL;
	while (ft_is_link(data[i]) != 1)
		i++;
	if (data[i - 1] != NULL && (ft_is_room(data[i - 1]) == 0
								&& ft_is_comment(data[i - 1]) == 0))
		ft_err();
	while (data[i] != NULL)
	{
		if (ft_is_comment(data[i]) == 1)
		{
			i++;
			break ;
		}
		if (ft_is_link(data[i]) == 0)
			ft_err();
		ft_links_help(data, names, i, links);
		i++;
	}
	return (links[1]);
}
