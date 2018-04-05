/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_buffer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 02:30:53 by thchin            #+#    #+#             */
/*   Updated: 2017/02/23 04:07:04 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_z_buffer(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (HEIGHT > i)
	{
		env->z_buffer[i][j] = env->z_min;
		j += 1;
		if (WIDTH <= j)
		{
			i += 1;
			j = 0;
		}
	}
}