/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 22:51:10 by ederbano          #+#    #+#             */
/*   Updated: 2017/03/06 16:54:40 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct		s_llist{
	struct s_llist	*next;
	int				dscr;
	char			*buff;

}					t_llist;

int					get_next_line(const int fd, char **line);

#endif
