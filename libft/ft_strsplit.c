/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:47:29 by thchin            #+#    #+#             */
/*   Updated: 2016/11/16 18:28:53 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	len(char const *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len += 1;
		i += 1;
	}
	return (len);
}

static int		countwords(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (0 < len(s, i, c))
		{
			words += 1;
			i += len(s, i, c);
		}
		else
			i += 1;
	}
	return (words);
}

static char		**splitwords(char const *s, char c, char **array, int i)
{
	int	j;

	j = 0;
	while (j < countwords(s, c))
	{
		if (0 < len(s, i, c))
		{
			if (NULL == (array[j] = ft_strsub(s, i, len(s, i, c))))
				return (NULL);
			j += 1;
			i += len(s, i, c);
		}
		else
			i += 1;
	}
	array[j] = NULL;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		i;

	i = 0;
	if (NULL == s || '\0' == c)
		return (NULL);
	array = (char **)malloc((countwords(s, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	if (NULL == (array = splitwords(s, c, array, i)))
		return (NULL);
	return (array);
}
