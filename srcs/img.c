/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:44:43 by thchin            #+#    #+#             */
/*   Updated: 2017/02/23 08:09:01 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/fdf.h"

void	img_put_pixel(t_env *env, int x, int y, int color)
{
	char			*data;
	unsigned int	value;

	data = env->data;
	value = mlx_get_color_value(env->mlx, color);
	if (0 < x && WIDTH > x && 0 < y && HEIGHT > y)
		ft_memcpy(data + y * env->size_line + x * (env->bpp / 8), &value, 3);
}

void	fill_img(t_env *env, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		img_put_pixel(env, x, y, color);
		x += 1;
		if (WIDTH <= x)
		{
			x = 0;
			y += 1;
		}
	}
}

void	draw_img(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < env->y)
	{
		if (y < env->y - 1 && env->grid[y + 1][x].w > 0 &&
			x < env->x - 1 && env->grid[y][x + 1].w > 0 &&
			env->grid[y + 1][x + 1].w > 0 && (env->type == 0 || env->type == 2))
			scanline(x, y, env);
		if (y < env->y - 1 && env->grid[y + 1][x].w > 0 &&
			(env->type == 0 || env->type == 1))
			draw(env->grid[y][x], env->grid[y + 1][x], env);
		if (x < env->x - 1 && env->grid[y][x + 1].w > 0 &&
			(env->type == 0 || env->type == 1))
			draw(env->grid[y][x], env->grid[y][x + 1], env);
		x += 1;
		if (x >= env->x || 0 >= env->grid[y][x].w)
		{
			x = 0;
			y += 1;
		}
	}
}
