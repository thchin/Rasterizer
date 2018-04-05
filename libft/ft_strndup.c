/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:50:20 by thchin            #+#    #+#             */
/*   Updated: 2016/11/23 11:53:09 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(const char *str, int start, int end)
{
	int		i;
	char	*new;

	if (NULL == (new = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	i = 0;
	while (start < end)
	{
		new[i] = str[start];
		i += 1;
		start += 1;
	}
	new[i] = '\0';
	return (new);
}
