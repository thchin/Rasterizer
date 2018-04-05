/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfrustum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:44:51 by thchin            #+#    #+#             */
/*   Updated: 2016/12/22 11:30:25 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_glfrustum(t_frustum *frustum)
{
	frustum->left = 0.0f;
	frustum->right = WIDTH;
	frustum->top = 0.0f;
	frustum->bottom = HEIGHT;
	frustum->near = 0.1f;
	frustum->far = 1.f;
}

void	glfrustum(t_env *env, t_frustum *f)
{
	t_matrix	m;

	m = gl_loadempty();
	m.m[0] = 2 * f->near / (f->right - f->left);
	m.m[2] = (f->right - f->left) / (f->right + f->left);
	m.m[5] = 2 * f->near / (f->top - f->bottom);
	m.m[6] = (f->top + f->bottom) / (f->top - f->bottom);
	m.m[10] = -((f->far + f->near) / (f->far - f->near));
	m.m[11] = -(2 * f->far * f->near / (f->far - f->near));
	m.m[14] = -1.0f;
	mult_matrix(env, m);
}
