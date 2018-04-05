/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:22:56 by thchin            #+#    #+#             */
/*   Updated: 2016/12/07 18:27:50 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

t_vector	min_vector(t_vector v1, t_vector v2)
{
	t_vector	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

t_vector	div_vector(t_vector v, float div)
{
	t_vector	result;

	result.x = v.x / div;
	result.y = v.y / div;
	result.z = v.z / div;
	return (result);
}

t_vector	mult_vector(t_vector v, float multi)
{
	t_vector	result;

	result.x = v.x * multi;
	result.y = v.y * multi;
	result.z = v.z * multi;
	return (result);
}

t_vector	scal_vector(t_vector v1, t_vector v2)
{
	t_vector	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

float		norm_vector(t_vector v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}
