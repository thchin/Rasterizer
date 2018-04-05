/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:47:56 by thchin            #+#    #+#             */
/*   Updated: 2016/11/16 17:47:57 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlentrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	spaces;

	i = 0;
	j = 0;
	spaces = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i += 1;
	while (s[i] != '\0')
	{
		if (s[i] != '\n' && s[i] != '\t' && s[i] != ' ')
			spaces = 0;
		else
			spaces += 1;
		j += 1;
		i += 1;
	}
	return (j - spaces);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	char			*str;

	if (NULL == s)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlentrim(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i += 1;
	while (j < len)
	{
		str[j] = s[i];
		j += 1;
		i += 1;
	}
	str[j] = '\0';
	return (str);
}
