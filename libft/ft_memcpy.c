/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:41:46 by thchin            #+#    #+#             */
/*   Updated: 2016/11/16 17:41:47 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (0 == n || dst == src)
		return (dst);
	n -= 1;
	while (0 < n)
	{
		*s1 = *s2;
		s1 += 1;
		s2 += 1;
		n -= 1;
	}
	*s1 = *s2;
	return (dst);
}
