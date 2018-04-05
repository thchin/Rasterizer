/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:40:33 by thchin            #+#    #+#             */
/*   Updated: 2016/11/27 00:28:44 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list *list, void (*del)(void *, size_t))
{
	t_node	*node;
	t_node	*tmp;

	if ((void *)0 == list)
		return ;
	node = list->head;
	while ((void *)0 != node)
	{
		tmp = node;
		node = node->next;
		ft_lstdelone(tmp, del);
	}
}
