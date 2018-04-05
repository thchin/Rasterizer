/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:47:02 by thchin            #+#    #+#             */
/*   Updated: 2016/11/16 17:47:04 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	if (NULL == (ptr = (char *)malloc((size + 1) * sizeof(char))))
		return ((void *)0);
	i = 0;
	while (i <= size)
	{
		ptr[i] = '\0';
		i += 1;
	}
	return (ptr);
}
