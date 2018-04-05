/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfreeone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 02:12:25 by thchin            #+#    #+#             */
/*   Updated: 2016/12/01 12:34:55 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstfreeone(t_list *list, t_node *node)
{
	t_node	*tmp;

	if (NULL == list || NULL == node)
		return ;
	if (list->head == node)
	{
		list->head = node->next;
		free(node->data);
		free(node);
		node = NULL;
		list->size -= 1;
		return ;
	}
	tmp = list->head;
	while (node != tmp->next && NULL != tmp)
		tmp = tmp->next;
	if (list->tail == node)
		list->tail = tmp;
	if (NULL != tmp)
		tmp->next = node->next;
	free(node->data);
	free(node);
	node = NULL;
	list->size -= 1;
}
