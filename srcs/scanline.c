/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:43:04 by thchin            #+#    #+#             */
/*   Updated: 2017/02/24 00:05:12 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fdf.h"

#include <stdio.h>

void	fill_line(t_edge *e1, t_edge *e2, int y, t_env *env)
{
	int		x;
	float	z;
	float	zyi;

	if (e1->zmin != e2->zmin && e1->xmin != e2->xmin)
		zyi = (1 / ((e2->xmin - e1->xmin) / (e2->zmin - e1->zmin)));
	else
		zyi = 0;
	x = e1->xmin;
	z = e1->zmin;
	while (x < e2->xmin)
	{
		if (1 == in_viewport(x, y, env))
			if (z <= env->z_buffer[y][x])
			{
				img_put_pixel(env, x, y, set_color(env, 0));
				env->z_buffer[y][x] = z;
			}
		z += zyi;
		x += 1;
	}
}

void	draw_line(t_list *list, int y, t_env *env)
{
	t_node	*node;
	t_edge	*e1;
	t_edge	*e2;

	node = list->head;
	while (NULL != node)
	{
		e1 = (t_edge *)node->data;
		e2 = (t_edge *)node->next->data;
		fill_line(e1, e2, y, env);
		node = node->next->next;
	}
}

void	increment_x(t_list *list)
{
	t_node	*node;
	t_edge	*edge;

	node = list->head;
	while (NULL != node)
	{
		edge = (t_edge *)node->data;
		edge->xmin += edge->xi;
		edge->hmin += edge->hi;
		node = node->next;
	}
}

void	scanline(int x, int y, t_env *env)
{
	int			current_y;

	env->sc_ymin = HEIGHT;
	env->sc_ymax = 0.0f;
	init_edge(0, env->grid[y][x], env->grid[y][x + 1], env);
	init_edge(1, env->grid[y][x + 1], env->grid[y + 1][x + 1], env);
	init_edge(2, env->grid[y + 1][x + 1], env->grid[y + 1][x], env);
	init_edge(3, env->grid[y + 1][x], env->grid[y][x], env);
	sort_edge(env->edge);
	init_edge_table(env->edge, env->edge_table);
	current_y = env->sc_ymin;
	while (env->sc_ymax > current_y - 1)
	{
		add_edge(env->edge_table, env->active_edge, current_y);
		remove_edge(env->active_edge, current_y);
		env->active_edge = sort_active(env->active_edge);
		draw_line(env->active_edge, current_y, env);
		increment_x(env->active_edge);
		current_y += 1;
	}
}
