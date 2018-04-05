/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:32:22 by thchin            #+#    #+#             */
/*   Updated: 2017/02/24 00:52:26 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define ESCAPE 53
#define LEFT 123
#define RIGHT 124
#define DOWN 125
#define UP 126
#define PLUS 69
#define MINUS 78
#define EIGHT 91
#define TWO 84
#define FOUR 86
#define SIX 88
#define A 0
#define D 2
#define R 15
#define S 1
#define W 13
#define LEFT 123
#define RIGHT 124
#define C 8
#define Q 12
#define E 14
#define V 9

void	translate_event(int keycode, t_env *env)
{
	if (A == keycode)
		env->translatex += 1;
	if (D == keycode)
		env->translatex -= 1;
	if (S == keycode)
		env->translatey -= 1;
	if (W == keycode)
		env->translatey += 1;
	if (PLUS == keycode)
		env->translatez -= 10;
	if (MINUS == keycode)
		env->translatez += 10;
}

void	rotate_event(int keycode, t_env *env)
{
	if (EIGHT == keycode)
		env->rotatex -= 10;
	if (TWO == keycode)
		env->rotatex += 10;
	if (FOUR == keycode)
		env->rotatey -= 10;
	if (SIX == keycode)
		env->rotatey += 10;
	if (LEFT == keycode)
		env->rotatez -= 10;
	if (RIGHT == keycode)
		env->rotatez += 10;
	if (env->rotatex > 360 || env->rotatex < -360)
		env->rotatex = 0;
	if (env->rotatey > 360 || env->rotatey < -360)
		env->rotatey = 0;
	if (env->rotatez > 360 || env->rotatez < -360)
		env->rotatez = 0;
}

void	other_event(int keycode, t_env *env)
{
	if (V == keycode)
		env->color += 1;
	if (10 <= env->color)
		env->color = 0;
	if (C == keycode)
		env->type += 1;
	if (3 <= env->type)
		env->type = 0;
}

int		key_hook(int keycode, t_env *env)
{
	if (ESCAPE == keycode)
		clear_env(env);
	translate_event(keycode, env);
	rotate_event(keycode, env);
	other_event(keycode, env);
	if (Q == keycode)
		env->scalez -= 0.1f;
	if (E == keycode)
		env->scalez += 0.1f;
	if (R == keycode)
	{
		env->translatex = 0;
		env->translatey = 0;
		env->translatez = 0;
	}
	print_img(env);
	return (0);
}
