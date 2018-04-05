/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 04:21:11 by thchin            #+#    #+#             */
/*   Updated: 2017/02/23 04:22:04 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_list	*sort_active(t_list *list)
{
	t_node	*node;
	t_node	*tmp;
	t_edge	*tmp_edge;

	if (1 >= list->size)
		return (list);
	node = list->head;
	tmp = node->next;
	while (NULL != node->next)
	{
		if (((t_edge *)node->data)->xmin > ((t_edge *)tmp->data)->xmin)
		{
			tmp_edge = (t_edge *)node->data;
			node->data = tmp->data;
			tmp->data = (void *)tmp_edge;
		}
		tmp = tmp->next;
		if (NULL == tmp)
		{
			node = node->next;
			tmp = node->next;
		}
	}
	return (list);
}

void	init_edge_table(t_edge *edge[4], t_list *list)
{
	t_node	*node;
	int		i;

	i = 0;
	while (4 > i)
	{
		if (edge[i]->hline == 0)
		{
			if (NULL == (node = ft_nodenew(edge[i], sizeof(edge[i]))))
				return ;
			ft_lstpushback(list, node);
		}
		i += 1;
	}
}
