/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glulookat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:33:47 by thchin            #+#    #+#             */
/*   Updated: 2016/12/23 13:43:08 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_glulookat(t_env *env, t_lookat *lookat)
{
	lookat->eye.x = env->translatex;
	lookat->eye.y = env->translatey;
	lookat->eye.z = env->translatez;
	lookat->center.x = 0.0f;
	lookat->center.y = 0.0f;
	lookat->center.z = 0.0f;
	lookat->up.x = 0.0f;
	lookat->up.y = 1.0f;
	lookat->up.z = 0.0f;
}

void	glulookat(t_env *env, t_lookat *lookat)
{
	t_matrix	m;
	t_vector	f;
	t_vector	s;
	t_vector	u;

	f = min_vector(lookat->center, lookat->eye);
	f = div_vector(f, norm_vector(f));
	s = scal_vector(f, div_vector(lookat->up, norm_vector(lookat->up)));
	u = scal_vector(div_vector(s, norm_vector(s)), f);
	m = gl_loadidentity();
	m.m[0] = s.x;
	m.m[1] = s.y;
	m.m[2] = s.z;
	m.m[4] = u.x;
	m.m[5] = u.y;
	m.m[6] = u.z;
	m.m[8] = -f.x;
	m.m[9] = -f.y;
	m.m[10] = -f.z;
	m.m[15] = 1;
	mult_matrix(env, m);
	gl_translatef(env, -(lookat->eye.x), -(lookat->eye.y), -(lookat->eye.z));
}
