/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:46:35 by thchin            #+#    #+#             */
/*   Updated: 2016/11/16 17:46:36 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i += 1;
	while (s2[j] != '\0' && j < n)
	{
		s1[i] = s2[j];
		i += 1;
		j += 1;
	}
	s1[i] = '\0';
	return (s1);
}