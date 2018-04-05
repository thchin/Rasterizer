/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:45:41 by thchin            #+#    #+#             */
/*   Updated: 2016/11/22 16:25:12 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	if ((void *)0 == s1 || (void *)0 == s2)
		return (0);
	i = 0;
	j = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(j * sizeof(char));
	if (str == NULL)
		return (NULL);
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i += 1;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i += 1;
		j += 1;
	}
	str[i] = '\0';
	return (str);
}
