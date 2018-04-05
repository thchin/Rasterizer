/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 03:51:13 by thchin            #+#    #+#             */
/*   Updated: 2017/02/23 03:57:03 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_node	*ft_lstremoveone(t_list *list, t_node *node)
{
	t_node	*tmp;

	if (list->head == node)
	{
		list->head = node->next;
		free(node);
		list->size -= 1;
		node = list->head;
	}
	else
	{
		tmp = list->head;
		while (node != tmp->next && NULL != tmp)
			tmp = tmp->next;
		if (list->tail == node)
			list->tail = tmp;
		if (NULL != tmp)
			tmp->next = node->next;
		free(node);
		list->size -= 1;
		node = tmp->next;
	}
	return (node);
}
