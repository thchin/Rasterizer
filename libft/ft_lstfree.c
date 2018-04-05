/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:43:26 by thchin            #+#    #+#             */
/*   Updated: 2016/12/01 13:15:39 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstfree(t_list *list)
{
	t_node	*tmp;
	t_node	*node;

	if (NULL == list)
		return ;
	node = list->head;
	while (NULL != node)
	{
		tmp = node->next;
		free(node->data);
		free(node);
		node = NULL;
		node = tmp;
	}
	free(list);
	list = NULL;
}
