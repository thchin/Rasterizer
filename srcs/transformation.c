/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:26:08 by thchin            #+#    #+#             */
/*   Updated: 2016/12/23 11:17:17 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"
#include <math.h>

void	gl_translatef(t_env *env, float x, float y, float z)
{
	t_matrix	m;

	m = gl_loadidentity();
	m.m[0] = 1.0f;
	m.m[3] = x;
	m.m[5] = 1.0f;
	m.m[7] = y;
	m.m[10] = 1.0f;
	m.m[11] = z;
	m.m[15] = 1.0f;
	mult_matrix(env, m);
}

void	gl_rotatexf(t_env *env, float angle)
{
	t_matrix	m;

	angle = ft_degreetoradian(angle);
	m = gl_loadidentity();
	m.m[0] = 1.0f;
	m.m[5] = cosf(angle);
	m.m[6] = -sinf(angle);
	m.m[9] = sinf(angle);
	m.m[10] = cos(angle);
	m.m[15] = 1.0f;
	mult_matrix(env, m);
}

void	gl_rotateyf(t_env *env, float angle)
{
	t_matrix	m;

	angle = ft_degreetoradian(angle);
	m = gl_loadidentity();
	m.m[0] = cosf(angle);
	m.m[2] = sinf(angle);
	m.m[5] = 1.0f;
	m.m[8] = -sinf(angle);
	m.m[10] = cosf(angle);
	m.m[15] = 1.0f;
	mult_matrix(env, m);
}

void	gl_rotatezf(t_env *env, float angle)
{
	t_matrix	m;

	angle = ft_degreetoradian(angle);
	m = gl_loadidentity();
	m.m[0] = cosf(angle);
	m.m[1] = -sinf(angle);
	m.m[4] = sinf(angle);
	m.m[5] = cosf(angle);
	m.m[10] = 1.0f;
	m.m[15] = 1.0f;
	mult_matrix(env, m);
}

void	gl_scalef(t_env *env, float x, float y, float z)
{
	t_matrix	m;

	m = gl_loadidentity();
	m.m[0] = x;
	m.m[5] = y;
	m.m[10] = z;
	m.m[15] = 1.0f;
	mult_matrix(env, m);
}
