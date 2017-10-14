/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ederbano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:05:19 by ederbano          #+#    #+#             */
/*   Updated: 2017/01/09 16:05:08 by ederbano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (!alst || !*alst || !del)
		return ;
	tmp = (*alst)->next;
	ft_lstdel(&tmp, del);
	ft_lstdelone(alst, del);
}
