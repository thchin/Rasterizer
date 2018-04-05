/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 03:30:16 by thchin            #+#    #+#             */
/*   Updated: 2017/02/23 07:46:12 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fdf.h"

void	init_edgex(int i, t_vertex v1, t_vertex v2, t_env *env)
{
	if (v1.x != v2.x && v1.y != v2.y)
		env->edge[i]->xi = 1 / ((v2.y - v1.y) / (v2.x - v1.x));
	else
		env->edge[i]->xi = 0.0f;
	if (env->edge[i]->xi >= 0.0f)
	{
		env->edge[i]->xmin = v1.x < v2.x ? v1.x : v2.x;
		env->edge[i]->zmin = v1.x < v2.x ? v1.w : v2.w;
	}
	else
	{
		env->edge[i]->xmin = v1.x < v2.x ? v2.x : v1.x;
		env->edge[i]->zmin = v1.x < v2.w ? v2.z : v1.w;
	}
}

void	init_edge(int i, t_vertex v1, t_vertex v2, t_env *env)
{
	if ((int)v1.y == (int)v2.y)
		env->edge[i]->hline = 1;
	else
		env->edge[i]->hline = 0;
	init_edgex(i, v1, v2, env);
	if (v1.z != v2.z && v1.y != v2.y)
		env->edge[i]->zi = 1 / ((v2.w - v1.w) / (v2.y - v1.y));
	else
		env->edge[i]->zi = 0.0f;
	env->edge[i]->ymin = v1.y < v2.y ? v1.y : v2.y;
	env->edge[i]->ymax = v1.y > v2.y ? v1.y : v2.y;
	if (env->sc_ymin > env->edge[i]->ymin)
		env->sc_ymin = env->edge[i]->ymin;
	if (env->sc_ymax < env->edge[i]->ymax)
		env->sc_ymax = env->edge[i]->ymax;
}

void	sort_edge(t_edge *edge[4])
{
	int			i;
	int			j;
	t_edge		*tmp;

	i = 0;
	j = 1;
	tmp = NULL;
	while (3 > i)
	{
		if (edge[i]->ymin > edge[j]->ymin || edge[i]->hline == 1 ||
			(edge[i]->ymin == edge[j]->ymin && edge[i]->xmin > edge[j]->xmin))
		{
			tmp = edge[i];
			edge[i] = edge[j];
			edge[j] = tmp;
		}
		j += 1;
		if (4 <= j)
		{
			i += 1;
			j = i + 1;
		}
	}
}

void	remove_edge(t_list *active, int y)
{
	t_node	*node;
	t_edge	*edge;

	if (active->size == 0)
		return ;
	node = active->head;
	while (NULL != node)
	{
		edge = (t_edge *)node->data;
		if (edge->ymax == y)
			node = ft_lstremoveone(active, node);
		else
			node = node->next;
	}
}

void	add_edge(t_list *table, t_list *active, int y)
{
	t_node	*node;
	t_edge	*edge;

	node = table->head;
	while (NULL != node)
	{
		edge = (t_edge *)node->data;
		if (edge->ymin == y)
			node = ft_lstswitch(table, active, node);
		else
			node = node->next;
	}
}
