/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 12:09:42 by thchin            #+#    #+#             */
/*   Updated: 2017/02/23 06:14:25 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_viewport(t_view *view)
{
	view->top = 0;
	view->bottom = HEIGHT;
	view->left = 0;
	view->right = WIDTH;
}

int		in_gridviewport(int x, int y, t_env *env)
{
	if (env->grid[y][x].x > env->view.left &&
		env->grid[y][x].x < env->view.right &&
		env->grid[y][x].y > env->view.top &&
		env->grid[y][x].y < env->view.bottom && env->grid[y][x].w > 0)
		return (1);
	return (0);
}

int		in_viewport(int x, int y, t_env *env)
{
	if (x > env->view.left && x < env->view.right &&
		y > env->view.top && y < env->view.bottom)
		return (1);
	return (0);
}
