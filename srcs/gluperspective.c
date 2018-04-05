/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gluperspective.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:00:09 by thchin            #+#    #+#             */
/*   Updated: 2017/02/24 00:01:34 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

void	set_gluperspective(t_pers *pers)
{
	pers->fovy = 120.0f;
	pers->aspect = 4.0f / 3.0f;
	pers->znear = 0.00001f;
	pers->zfar = 100.0f;
}

void	gluperspective(t_env *env, t_pers *pers)
{
	t_matrix	m;
	float		f;

	m = gl_loadidentity();
	f = 1 / (tan(pers->fovy / 2));
	m.m[0] = f / pers->aspect;
	m.m[5] = f;
	m.m[10] = (pers->zfar + pers->znear) / (pers->znear - pers->zfar);
	m.m[11] = (2 * pers->zfar * pers->znear) / (pers->znear - pers->zfar);
	m.m[14] = -1.0f;
	mult_matrix(env, m);
}
