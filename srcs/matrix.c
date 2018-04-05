/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:45:02 by thchin            #+#    #+#             */
/*   Updated: 2017/02/23 07:47:00 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_matrix	gl_loadidentity(void)
{
	t_matrix	m;
	int			i;

	i = 0;
	while (16 > i)
	{
		m.m[i] = 0.0f;
		i += 1;
	}
	m.m[0] = 1.0f;
	m.m[5] = 1.0f;
	m.m[10] = 1.0f;
	m.m[15] = 1.0f;
	return (m);
}

t_matrix	gl_loadempty(void)
{
	t_matrix	m;
	int			i;

	i = 0;
	while (16 > i)
	{
		m.m[i] = 0.0f;
		i += 1;
	}
	return (m);
}

void		copy_matrix(t_matrix *a, t_matrix b)
{
	int	i;

	i = 0;
	while (16 > i)
	{
		a->m[i] = b.m[i];
		i += 1;
	}
}

void		mult_matrix(t_env *env, t_matrix a)
{
	t_matrix	b;
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	b = gl_loadempty();
	while (4 > i)
	{
		b.m[j * 4 + i] += env->matrix->m[k * 4 + i] * a.m[j * 4 + k];
		k += 1;
		if (4 <= k)
		{
			j += 1;
			k = 0;
		}
		if (4 <= j)
		{
			i += 1;
			j = 0;
		}
	}
	copy_matrix(env->matrix, b);
}

t_vertex	matrix_mul_vec(t_matrix *m, t_vertex v)
{
	t_vertex	result;

	result.x = m->m[0] * v.x + m->m[1] * v.y + m->m[2] * v.z + m->m[3] * v.w;
	result.y = m->m[4] * v.x + m->m[5] * v.y + m->m[6] * v.z + m->m[7] * v.w;
	result.z = m->m[8] * v.x + m->m[9] * v.y + m->m[10] * v.z + m->m[11] * v.w;
	result.w = m->m[12] * v.x + m->m[13] * v.y;
	result.w += m->m[14] * v.z + m->m[15] * v.w;
	return (result);
}
