/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:00:25 by thchin            #+#    #+#             */
/*   Updated: 2017/03/01 23:26:54 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "../includes/fdf.h"

int			tab_len(char **tab)
{
	int	i;

	i = 0;
	while (NULL != tab[i])
		i += 1;
	return (i);
}

void		tab_free(char **tab)
{
	int	i;

	i = 0;
	while (NULL != tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i += 1;
	}
	free(tab);
	tab = NULL;
}

t_vertex	*char_to_vertex(char **tab, int x, int y)
{
	t_vertex	*line;
	int			i;

	if (NULL == (line = (t_vertex *)malloc(sizeof(t_vertex) * x)))
		return (NULL);
	i = 0;
	while (i < x)
	{
		if (i < tab_len(tab))
		{
			line[i].x = i;
			line[i].y = y;
			line[i].z = ft_atoi(tab[i]);
			line[i].w = 1.0f;
		}
		else
		{
			line[i].x = 0.0f;
			line[i].y = 0.0f;
			line[i].z = 0.0f;
			line[i].w = 0.0f;
		}
		i += 1;
	}
	return (line);
}

int			update_list(t_env *env)
{
	char		**tab;
	t_vertex	*line;
	t_node		*node;
	int			y;

	node = env->list->head;
	y = 0;
	while (NULL != node)
	{
		tab = (char **)node->data;
		if (NULL == (line = char_to_vertex(tab, env->x, y)))
			return (0);
		tab_free(tab);
		node->data = (void *)line;
		node = node->next;
		y += 1;
	}
	return (1);
}

int			get_map(t_env *env, int fd)
{
	t_node		*node;
	char		*line;
	char		**tab;

	while (0 < get_next_line(fd, &line))
	{
		if (NULL == (tab = ft_strsplit(line, ' ')))
			return (0);
		if (env->x < tab_len(tab))
			env->x = tab_len(tab);
		if (NULL == (node = ft_nodenew((void *)tab, sizeof(tab))))
			return (0);
		ft_lstpushback(env->list, node);
		env->y += 1;
	}
	if (0 == update_list(env))
		return (0);
	if (0 == create_grid(env))
		return (0);
	return (1);
}
