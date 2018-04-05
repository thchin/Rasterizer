/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:39:38 by thchin            #+#    #+#             */
/*   Updated: 2016/11/16 17:39:40 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		numlen(int n)
{
	int	exp;
	int	len;

	exp = 1;
	len = 0;
	if (n < 0)
		len += 1;
	else
		n = -n;
	while (n / exp < -9)
	{
		exp *= 10;
		len += 1;
	}
	return (len + 1);
}

static char		*convertitoa(int n, char *str)
{
	int	exp;
	int	i;

	exp = 1;
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i += 1;
	}
	else
		n = -n;
	while (n / exp < -9)
		exp *= 10;
	while (exp > 0)
	{
		str[i] = '0' - (n / exp);
		n %= exp;
		exp /= 10;
		i += 1;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = numlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = convertitoa(n, str);
	return (str);
}
