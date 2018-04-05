/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:47:12 by thchin            #+#    #+#             */
/*   Updated: 2016/11/16 18:28:45 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = 0;
	while (s2[len] != '\0')
		len += 1;
	if (len == 0)
		return ((char *)s1);
	if (len > ft_strlen(s1))
		return (NULL);
	while (n > 0)
	{
		if (0 == (ft_strncmp(s1, s2, len)) && n >= len)
			return ((char *)s1);
		n -= 1;
		s1 += 1;
	}
	return (NULL);
}
