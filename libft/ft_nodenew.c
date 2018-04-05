/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 00:38:50 by thchin            #+#    #+#             */
/*   Updated: 2016/11/27 05:42:39 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_node	*ft_nodenew(void *data, size_t data_size)
{
	t_node	*node;

	if (NULL == (node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	if (NULL == data)
	{
		node->data = NULL;
		node->data_size = 0;
	}
	else
	{
		node->data = data;
		node->data_size = data_size;
	}
	node->next = NULL;
	return (node);
}
