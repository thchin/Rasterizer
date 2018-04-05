/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:40:56 by thchin            #+#    #+#             */
/*   Updated: 2016/11/27 00:47:25 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *list, t_node *(*f)(t_node *node))
{
	t_list	*new_list;
	t_node	*node;
	t_node	*tmp;

	if (NULL == (new_list = ft_lstnew()))
		return (NULL);
	node = list->head;
	while (NULL != node)
	{
		if (NULL == (tmp = ft_nodenew(NULL, 0)))
			return (NULL);
		tmp = f(node);
		ft_lstpushback(new_list, tmp);
		node = node->next;
	}
	return (new_list);
}
