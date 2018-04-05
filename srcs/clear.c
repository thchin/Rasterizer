/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:16:14 by thchin            #+#    #+#             */
/*   Updated: 2017/02/23 03:26:20 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "../includes/fdf.h"

void	clear_table(t_env *env)
{
	int	i;

	if (NULL != env->grid)
	{
		i = 0;
		while (i < env->y && NULL != env->grid[i])
		{
			free(env->grid[i]);
			i += 1;
		}
		free(env->grid);
	}
	if (NULL != env->z_buffer)
	{
		i = 0;
		while (i < HEIGHT && NULL != env->z_buffer[i])
		{
			free(env->z_buffer[i]);
			i += 1;
		}
		free(env->z_buffer);
	}
}

void	clear_list(t_env *env)
{
	if (NULL != env->list)
		ft_lstfree(env->list);
	if (NULL != env->edge_table)
		ft_lstfree(env->edge_table);
	if (NULL != env->active_edge)
		ft_lstfree(env->active_edge);
}

void	clear_edge(t_env *env)
{
	int	i;

	i = 0;
	while (NULL != env->edge[i] && i < 4)
	{
		free(env->edge[i]);
		i += 1;
	}
}

void	clear_mlx(t_env *env)
{
	if (NULL != env->img)
		mlx_destroy_image(env->mlx, env->img);
	if (NULL != env->win)
		free(env->win);
	if (NULL != env->mlx)
		free(env->mlx);
}

void	clear_env(t_env *env)
{
	clear_mlx(env);
	clear_list(env);
	clear_table(env);
	clear_edge(env);
	if (NULL != env->matrix)
		free(env->matrix);
	free(env);
	exit(0);
}
