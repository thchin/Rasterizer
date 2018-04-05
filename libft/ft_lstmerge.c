/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:07:21 by thchin            #+#    #+#             */
/*   Updated: 2016/11/27 00:52:01 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmerge(t_list *list1, t_list *list2)
{
	if (NULL == list2)
		return ;
	if (NULL == list1)
		list1 = list2;
	else
		list1->tail = list2->head;
}
