/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:10:12 by thchin            #+#    #+#             */
/*   Updated: 2017/02/23 23:46:41 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "../includes/fdf.h"

void	create_z_buffer(t_env *env)
{
	int	i;

	i = 0;
	env->z_buffer = NULL;
	if (NULL == (env->z_buffer = (float **)malloc(sizeof(float *) * HEIGHT)))
		clear_env(env);
	while (i < HEIGHT)
	{
		env->z_buffer[i] = NULL;
		if (NULL == (env->z_buffer[i] = (float *)malloc(sizeof(float) * WIDTH)))
			clear_env(env);
		i += 1;
	}
}

void	create_list(t_env *env)
{
	env->list = NULL;
	env->edge_table = NULL;
	env->active_edge = NULL;
	if (NULL == (env->list = ft_lstnew()))
		clear_env(env);
	if (NULL == (env->edge_table = ft_lstnew()))
		clear_env(env);
	if (NULL == (env->active_edge = ft_lstnew()))
		clear_env(env);
}

void	create_edge(t_env *env)
{
	int	i;

	i = 0;
	while (4 > i)
	{
		env->edge[i] = NULL;
		if (NULL == (env->edge[i] = (t_edge *)malloc(sizeof(t_edge))))
			clear_env(env);
		i += 1;
	}
}

void	init_mlx(t_env *env)
{
	env->mlx = NULL;
	env->win = NULL;
	env->img = NULL;
	env->data = NULL;
	if (NULL == (env->mlx = mlx_init()))
		clear_env(env);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "FdF");
	if (NULL == env->win)
		clear_env(env);
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (NULL == env->img)
		clear_env(env);
	env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->size_line),
								(&(env->endian)));
	if (NULL == env->data)
		clear_env(env);
}

t_env	*init_env(void)
{
	t_env	*env;

	env = NULL;
	if (NULL == (env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	init_mlx(env);
	create_z_buffer(env);
	create_list(env);
	create_edge(env);
	env->matrix = NULL;
	if (NULL == (env->matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		clear_env(env);
	copy_matrix(env->matrix, gl_loadidentity());
	env->x = 0;
	env->y = 0;
	env->translatex = 0.0f;
	env->translatey = 0.0f;
	env->translatez = 500.0f;
	env->rotatex = 30;
	env->rotatey = 0;
	env->rotatez = 45;
	env->type = 0;
	env->scalez = 1.0f;
	env->color = 0;
	return (env);
}
