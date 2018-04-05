/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:45:52 by thchin            #+#    #+#             */
/*   Updated: 2016/11/17 15:04:07 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(dst);
	if (len >= size)
		return (size + ft_strlen(src));
	while (dst[i] != '\0')
		i += 1;
	while (src[j] != '\0' && j < size - len - 1)
	{
		dst[i] = src[j];
		i += 1;
		j += 1;
	}
	while (i < size)
	{
		dst[i] = '\0';
		i += 1;
	}
	return (len + ft_strlen((char *)src));
}
