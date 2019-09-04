/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:32:03 by bcarlier          #+#    #+#             */
/*   Updated: 2018/12/14 14:39:54 by bcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *nxlist;

	list = *alst;
	while (list)
	{
		nxlist = list->next;
		del(list->content, list->content_size);
		free(list);
		list = nxlist;
	}
	*alst = NULL;
}
