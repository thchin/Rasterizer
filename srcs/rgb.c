/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 05:48:41 by thchin            #+#    #+#             */
/*   Updated: 2017/02/27 23:54:17 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	set_color(t_env *env, int flag)
{
	if ((0 == env->type && 0 == flag) || 1 == env->type || 2 == env->type)
	{
		if (0 == env->color)
			return (0x98F015);
		if (1 == env->color)
			return (0x0000FF);
		if (2 == env->color)
			return (0x00FF00);
		if (3 == env->color)
			return (0xFF0000);
		if (4 == env->color)
			return (0xA7E836);
		if (5 == env->color)
			return (0xEFB7F0);
		if (6 == env->color)
			return (0xE6636E);
		if (7 == env->color)
			return (0xFF5614);
		if (8 == env->color)
			return (0xC9150C);
		if (9 == env->color)
			return (0xE098C1);
	}
	return (0xFFFFFF);
}
