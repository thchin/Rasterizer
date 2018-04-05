/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:40:50 by thchin            #+#    #+#             */
/*   Updated: 2016/11/27 00:35:52 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *list, void (*f)(t_node *node))
{
	t_node	*node;

	node = list->head;
	while ((void *)0 != node)
	{
		f(node);
		node = node->next;
	}
}
