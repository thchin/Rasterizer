/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:47:38 by thchin            #+#    #+#             */
/*   Updated: 2016/11/16 18:29:03 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;

	len2 = 0;
	while (s2[len2] != '\0')
		len2 += 1;
	if (len2 == 0)
		return ((char *)s1);
	len1 = ft_strlen(s1);
	while (len1 >= len2)
	{
		len1 -= 1;
		if (0 == ft_strncmp(s1, s2, len2))
			return ((char *)s1);
		s1 += 1;
	}
	return (NULL);
}
