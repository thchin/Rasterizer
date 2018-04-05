/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:54:00 by thchin            #+#    #+#             */
/*   Updated: 2017/02/27 23:54:33 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/fdf.h"

int	print_img(t_env *env)
{
	update_grid(env);
	set_viewport(&(env->view));
	*(env->matrix) = gl_loadidentity();
	gl_scalef(env, 1, 1, env->scalez);
	gl_translatef(env, -(env->x / 2), -(env->y / 2), 0);
	set_glulookat(env, &(env->lookat));
	gl_rotatezf(env, env->rotatez);
	gl_rotatexf(env, env->rotatex);
	gl_rotateyf(env, env->rotatey);
	glulookat(env, &(env->lookat));
	set_gluperspective(&(env->pers));
	gluperspective(env, &(env->pers));
	matrix_grid(env);
	ortho_grid(env);
	init_z_buffer(env);
	fill_img(env, 0xFFFFFF);
	draw_img(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (1);
}
