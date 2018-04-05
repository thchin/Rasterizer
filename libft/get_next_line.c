/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:51:56 by thchin            #+#    #+#             */
/*   Updated: 2016/12/22 14:04:07 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "get_next_line.h"

#define SAVE gnl->save

static t_gnl	*ft_get_gnl(const int fd, t_list *list)
{
	t_node	*node;
	t_gnl	*gnl;

	node = list->head;
	while (NULL != node)
	{
		gnl = (t_gnl *)node->data;
		if (fd == gnl->fd)
			return (gnl);
		node = node->next;
	}
	return (NULL);
}

static t_gnl	*ft_update_list(const int fd, t_list *list)
{
	t_node	*node;
	t_gnl	*gnl;

	if (0 == list->size || NULL == (gnl = ft_get_gnl(fd, list)))
	{
		if (NULL == (gnl = (t_gnl *)malloc(sizeof(t_gnl))))
			return (NULL);
		gnl->fd = fd;
		if (NULL == (SAVE = ft_strnew(0)))
		{
			free(gnl);
			return (NULL);
		}
		if (NULL == (node = ft_nodenew((void *)gnl, sizeof(gnl))))
		{
			free(gnl);
			return (NULL);
		}
		ft_lstpushback(list, node);
	}
	return (gnl);
}

static int		ft_check_line(int ret, t_gnl *gnl, char **line)
{
	int		i;
	char	*tmp;

	i = ft_strclen(SAVE, '\n');
	if ('\n' == SAVE[i])
	{
		*line = ft_strndup(SAVE, 0, i);
		tmp = SAVE;
		if (NULL == (SAVE = ft_strndup(SAVE, i + 1, ft_strlen(SAVE))))
			return (-1);
		free(tmp);
		return (1);
	}
	if ('\0' == SAVE[i] && ret < BUFF_SIZE && i != 0)
	{
		if (NULL == (*line = ft_strdup(SAVE)))
			return (-1);
		ft_bzero(SAVE, ft_strlen(SAVE));
		return (1);
	}
	return (0);
}

static int		ft_get_line(const int fd, char **line, t_gnl *gnl, t_list *list)
{
	int		check;
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	ret = 1;
	while (0 < ret)
	{
		if (0 > (ret = read(fd, buff, BUFF_SIZE)))
			return (-1);
		buff[ret] = '\0';
		tmp = SAVE;
		if (NULL == (SAVE = ft_strjoin(SAVE, buff)))
			return (-1);
		free(tmp);
		check = ft_check_line(ret, gnl, line);
		if (0 != check)
			return (check);
	}
	free(SAVE);
	ft_lstfreeone(list, ft_lstfind(list, (void *)gnl));
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	t_gnl			*gnl;
	static t_list	*list = NULL;

	if (0 > fd || NULL == line || 0 > BUFF_SIZE)
		return (-1);
	if (NULL == list)
		if (NULL == (list = ft_lstnew()))
			return (-1);
	if (NULL == (gnl = ft_update_list(fd, list)))
		return (-1);
	ret = ft_get_line(fd, line, gnl, list);
	if (0 == ret && 0 == list->size)
	{
		free(list);
		list = NULL;
	}
	return (ret);
}
