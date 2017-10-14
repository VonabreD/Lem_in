/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:31:24 by ederbano          #+#    #+#             */
/*   Updated: 2017/03/02 23:04:14 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static t_llist	*ft_chk_list(int fd, t_llist *list)
{
	t_llist *tmp;

	if (!list)
	{
		list = (t_llist *)malloc(sizeof(t_llist));
		list->dscr = fd;
		list->buff = (char *)malloc(sizeof(char));
		list->next = NULL;
	}
	tmp = list;
	while (list->dscr != fd)
	{
		if (list->next == NULL)
		{
			list->next = (t_llist *)malloc(sizeof(t_llist));
			list->next->dscr = fd;
			list->next->buff = (char *)malloc(sizeof(char));
			list->next->next = NULL;
		}
		else
			list = list->next;
	}
	return (tmp);
}

static ssize_t	ft_helper(t_llist *list, char **line, ssize_t q)
{
	size_t	i;
	char	*ptr;

	i = 0;
	while (list->buff[i] != '\0' && q > -1)
	{
		if (list->buff[i] == '\n')
			q = -2;
		i++;
		if (list->buff[i] == '\0' && q == 0)
			q = -1;
		if (q < 0)
		{
			*line = (char *)malloc(sizeof(char) * (i + 2 + q));
			*line = ft_strncpy(*line, list->buff, i + 1 + q);
			line[0][i + 1 + q] = '\0';
			ptr = list->buff;
			list->buff = ft_strjoin("", &list->buff[i]);
			free(ptr);
		}
	}
	return (q);
}

static int		ft_read(int fd, t_llist *list, char **line)
{
	char	*str[2];
	ssize_t	q;

	q = 1;
	str[0] = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while (q > 0)
	{
		q = read(fd, str[0], BUFF_SIZE);
		str[0][q] = '\0';
		if (q > 0)
		{
			str[1] = list->buff;
			list->buff = ft_strjoin(list->buff, str[0]);
			free(str[1]);
			str[0] = ft_strncpy(str[0], "", BUFF_SIZE);
		}
		q = ft_helper(list, line, q);
	}
	free(str[0]);
	if (q == 0 && *line == NULL)
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_llist	*list;
	t_llist			*tmp;
	char			*str;

	if (fd < 0 || fd > OPEN_MAX || BUFF_SIZE < 0
			|| line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	list = ft_chk_list(fd, list);
	str = NULL;
	tmp = list;
	while (tmp->dscr != fd)
		tmp = tmp->next;
	if (ft_read(fd, tmp, &str) == 0)
		return (0);
	*line = str;
	return (1);
}
