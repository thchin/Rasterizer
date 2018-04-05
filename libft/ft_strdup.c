/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:45:10 by thchin            #+#    #+#             */
/*   Updated: 2016/11/16 18:27:56 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strdup(const char *s1)
{
	unsigned int	i;
	unsigned int	len;
	char			*dst;

	i = 0;
	len = ft_strlen(s1);
	if (NULL == (dst = (char *)malloc(len + 1 * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}
