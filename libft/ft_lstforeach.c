/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstforeach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:21:40 by thchin            #+#    #+#             */
/*   Updated: 2016/11/27 00:34:01 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstforeach(t_list *list, void (*f)(void *))
{
	t_node	*node;

	if ((void *)0 == list || (void *)0 == f)
		return ;
	node = list->head;
	while ((void *)0 != node)
	{
		f(node->data);
		node = node->next;
	}
}
