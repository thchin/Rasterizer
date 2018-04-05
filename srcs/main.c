/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:01:55 by thchin            #+#    #+#             */
/*   Updated: 2017/02/27 23:47:47 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_env	*env;
	int		fd;

	if (2 != ac)
		ft_putstr("error\n");
	else if (ac == 2)
	{
		if (NULL == (env = init_env()))
			return (0);
		if (0 > (fd = open(av[1], O_RDONLY)))
			return (0);
		if (0 == get_map(env, fd))
			return (0);
		close(fd);
		mlx_key_hook(env->win, key_hook, env);
		mlx_expose_hook(env->win, print_img, env);
		mlx_loop(env->mlx);
	}
	return (0);
}
