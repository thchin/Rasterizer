/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 13:17:42 by thchin            #+#    #+#             */
/*   Updated: 2016/12/22 14:03:53 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int	check_duplicate(const char *base, int i)
{
	int	j;

	j = i + 1;
	while ('\0' != base[j])
	{
		if (base[i] == base[j])
			return (1);
		j += 1;
	}
	return (0);
}

static int	check_base(const char *base)
{
	int	i;

	i = 0;
	if ((void *)0 == base)
		return (0);
	while ('\0' != base[i])
	{
		if (base[i] == '+' || base[i] == '-' || 1 == check_duplicate(base, i) ||
			(base[i] < '!' && base[i] > '~'))
			return (0);
		i += 1;
	}
	if (1 == i)
		return (0);
	return (i);
}

static void	get_first(const char *str, int i[2], int ibase)
{
	i = 0;
	while ('\f' == str[i[0]] || '\v' == str[i[0]] || '\r' == str[i[0]] ||
			'\n' == str[i[0]] || ' ' == str[i[0]] || '\t' == str[i[0]])
		i += 1;
	if ('-' == str[i[0]] || '+' == str[i[0]])
	{
		i[1] = i[0];
		i[0] += 1;
	}
	if (16 == ibase)
	{
		if ('0' == str[i[0]])
			if ('+' == str[i[0] + 1])
				i += 2;
	}
	if (8 == ibase)
		if ('0' == str[0])
			i[0] += 1;
}

int			ft_atoi_base(const char *str, const char *base)
{
	int	i[2];
	int	ibase;
	int	nb;
	int	operator;
	int	len;

	nb = 0;
	if (2 > (ibase = check_base(base)))
		return (0);
	get_first(str, i, ibase);
	operator = i[1];
	len = ft_nblen_base(&str[i[0]], base) - 1;
	while (-1 < ft_check_char(base[i[0]], base) && str[i[0]] != '\0')
	{
		nb += ft_check_char(base[i[0]], base) * ft_iterative_power(ibase, len);
		i[0] += 1;
		len -= 1;
	}
	if (-1 < operator && '-' == str[operator])
		nb = -nb;
	return (nb);
}
