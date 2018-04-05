/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:45:16 by thchin            #+#    #+#             */
/*   Updated: 2017/02/24 00:05:23 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>
#include <mlx.h>

t_draw	set_draw(t_vertex v1, t_vertex v2)
{
	t_draw	draw;

	draw.xa = v1.x;
	draw.ya = v1.y;
	draw.xb = v2.x;
	draw.yb = v2.y;
	draw.dx = ft_abs(draw.xb - draw.xa);
	draw.dy = ft_abs(draw.yb - draw.ya);
	draw.sx = draw.xa < draw.xb ? 1 : -1;
	draw.sy = draw.ya < draw.yb ? 1 : -1;
	draw.err = (draw.dx > draw.dy ? draw.dx : -(draw.dy)) / 2;
	if (v1.w <= 0 || v2.w <= 0)
		draw.w = -1;
	else
		draw.w = 1;
	return (draw);
}

void	draw(t_vertex v1, t_vertex v2, t_env *env)
{
	t_draw	draw;

	draw = set_draw(v1, v2);
	if ((draw.xa < env->view.left && draw.xb < env->view.left) ||
		(draw.xa > env->view.right && draw.xb > env->view.right) ||
		(draw.ya < env->view.top && draw.yb < env->view.top) ||
		(draw.ya > env->view.bottom && draw.yb > env->view.bottom))
		return ;
	while (draw.xa != draw.xb || draw.ya != draw.yb)
	{
		if (draw.xa > env->view.left && draw.xa < env->view.right &&
			draw.ya > env->view.top && draw.ya < env->view.bottom && draw.w > 0)
			img_put_pixel(env, draw.xa, draw.ya, set_color(env, 1));
		draw.e2 = draw.err;
		if (draw.e2 > -(draw.dx) && draw.xa != draw.xb)
		{
			draw.err -= draw.dy;
			draw.xa += draw.sx;
		}
		if (draw.e2 < draw.dy && draw.ya != draw.yb)
		{
			draw.err += draw.dx;
			draw.ya += draw.sy;
		}
	}
}
