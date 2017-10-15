/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 13:51:16 by ederbano          #+#    #+#             */
/*   Updated: 2017/10/14 13:51:26 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H
# include "get_next_line.h"
# include "libft/libft.h"

typedef struct		s_links{
	char			*name1;
	char			*name2;
	struct s_links	*next;
}					t_links;

typedef struct		s_way{
	char			*name;
	int				ant;
	struct s_way	*next;
	struct s_way	*pre;
	struct s_way	*end;
}					t_way;

typedef struct		s_tub{
	t_way			*way;
	int				finit;
	int				len;
}					t_tub;

typedef struct		s_names{
	int				pos;
	char			*name;
	int				dist;
	int				used;
	int				x;
	int				y;
	struct s_names	*next;
}					t_names;

typedef struct		s_que{
	t_names			*elem;
	struct s_que	*next;
}					t_que;

t_names				*ft_add_name(void);

int					ft_mod_atoi(const char *str);
int					ft_is_command(char *str);
int					ft_is_comment(char *str);
int					ft_is_ants(char *str);
int					ft_is_link(char *str);
int					ft_is_room(char *str);
int					ft_err(void);
char				*ft_first_wrd(char *str);
int					ft_take_y(char *str);
int					ft_take_x(char *str);
void				ft_init_names(t_names **start,
									t_names **names, char **data, int *i);
t_names				*ft_take_names(char **data);
void				ft_print_data(char **data);
void				ft_print_ways(int ants, t_tub *tub, char **data_in);
int					ft_print_step(t_tub *tub);
int					ft_err(void);
char				**ft_parse(int fd);
void				ft_init_links(t_links **links, t_links **start);
void				ft_links_help(char **data, t_names *name,
									int i, t_links **links);
t_links				*ft_take_links(char **data, t_names *names);
void				ft_command_help(int *c, char *str);
void				ft_commands(char **data);
void				ft_chk_names(t_names *names);
char				*ft_find_fst_name(t_names *names);
char				*ft_find_lst_name(t_names *names);
int					ft_num_lnk(t_links *links, char *name);
int					ft_num_ways(t_names *names, t_links *links);
t_que				*ft_queue_init(t_names *names);
t_names				*ft_fn(char *str, t_names *names);
t_names				*ft_name_find(char *str, t_names *names);
void				ft_push_queue(t_que *queue, t_names *elem);
int					ft_chk_dist(t_names *names);
void				ft_free_que(t_que *queue);
void				ft_brain(t_names *names, t_links *links);
t_way				*ft_way_init(char *str);
t_way				*ft_next_room(t_names *names, t_links *links, t_way *way);
int					ft_is_end(t_way *way, char *str);
t_way				*ft_find_way(t_names *names, t_links *links);
t_tub				*ft_tub_make(t_names *names, t_links *links);
int					ft_take_ants(char **data);
void				ft_chk_finit(t_tub **tub, char *str);
void				ft_sort_ways(t_tub **tub);
int					ft_count_ways(t_tub *tub, int ants);
int					ft_fill_rooms(t_tub *tub, int n_a);
void				ft_pre_ways(t_tub *tub);
void				ft_brain_help(t_que **que, t_names *ns, t_links *ln);
void				ft_links_test(char *str, t_names *names);

#endif
