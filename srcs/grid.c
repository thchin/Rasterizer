/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:43:01 by thchin            #+#    #+#             */
/*   Updated: 2017/02/23 07:46:22 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fdf.h"

int		create_grid(t_env *env)
{
	int	i;

	i = 0;
	if (NULL == (env->grid = (t_vertex **)malloc(sizeof(t_vertex *) * env->y)))
		return (0);
	while (i < env->y)
	{
		env->grid[i] = (t_vertex *)malloc(sizeof(t_vertex) * env->x);
		if (NULL == env->grid[i])
			return (0);
		i += 1;
	}
	return (1);
}

void	update_grid(t_env *env)
{
	t_node		*node;
	int			y;
	int			x;

	y = 0;
	x = 0;
	node = env->list->head;
	while (y < env->y && NULL != node)
	{
		env->grid[y][x].x = ((t_vertex *)node->data)[x].x;
		env->grid[y][x].y = ((t_vertex *)node->data)[x].y;
		env->grid[y][x].z = ((t_vertex *)node->data)[x].z;
		env->grid[y][x].w = ((t_vertex *)node->data)[x].w;
		x += 1;
		if (x >= env->x)
		{
			y += 1;
			x = 0;
			node = node->next;
		}
	}
}

void	matrix_grid(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < env->y)
	{
		if (0 != env->grid[y][x].w)
		{
			env->grid[y][x] = matrix_mul_vec(env->matrix, env->grid[y][x]);
			env->grid[y][x].x /= env->grid[y][x].w;
			env->grid[y][x].y /= env->grid[y][x].w;
			env->grid[y][x].z /= env->grid[y][x].w;
			if (((0 == y && x == 0) || env->grid[y][x].w > env->z_min) &&
				env->grid[y][x].w >= 0)
				env->z_min = env->grid[y][x].w;
		}
		x += 1;
		if (x >= env->x || 0 == env->grid[y][x].w)
		{
			y += 1;
			x = 0;
		}
	}
}

void	ortho_grid(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < env->y)
	{
		if (0 != env->grid[y][x].w)
		{
			env->grid[y][x].x = env->grid[y][x].x * WIDTH / 2 + WIDTH / 2;
			env->grid[y][x].y = env->grid[y][x].y * HEIGHT / 2 + HEIGHT / 2;
		}
		x += 1;
		if (x >= env->x || 0 == env->grid[y][x].w)
		{
			y += 1;
			x = 0;
		}
	}
}
