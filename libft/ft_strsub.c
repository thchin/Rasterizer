/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:47:46 by thchin            #+#    #+#             */
/*   Updated: 2016/11/16 17:47:47 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*str;

	if (NULL == s)
		return (NULL);
	i = start;
	j = 0;
	if (NULL == (str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (j < len)
	{
		str[j] = s[i];
		j += 1;
		i += 1;
	}
	str[j] = '\0';
	return (str);
}
