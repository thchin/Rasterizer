/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:16:33 by thchin            #+#    #+#             */
/*   Updated: 2016/11/27 02:17:04 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstfind(t_list *list, void *data_ref)
{
	t_node	*node;

	if ((void *)0 == list || (void *)0 == data_ref)
		return ((void *)0);
	node = list->head;
	while ((void *)0 != node)
	{
		if (node->data == data_ref)
			return (node);
		node = node->next;
	}
	return ((void *)0);
}
