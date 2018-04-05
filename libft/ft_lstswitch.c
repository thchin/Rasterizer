/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswitch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 04:00:51 by thchin            #+#    #+#             */
/*   Updated: 2017/02/23 04:03:33 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstswitch(t_list *src, t_list *dst, t_node *node)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (node == src->head)
		src->head = node->next;
	else
	{
		tmp2 = src->head;
		while (tmp2->next != node && NULL != tmp2)
			tmp2 = tmp2->next;
		tmp2->next = tmp2->next->next;
	}
	tmp = node->next;
	ft_lstpushback(dst, node);
	src->size -= 1;
	node = tmp;
	return (node);
}
