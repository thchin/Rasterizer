/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:38:36 by thchin            #+#    #+#             */
/*   Updated: 2016/11/16 17:48:48 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	operator;
	int	nb;

	i = 0;
	nb = 0;
	operator = -1;
	while (str[i] == '\f' || str[i] == '\v' || str[i] == '\r' ||
			str[i] == '\n' || str[i] == ' ' || str[i] == '\t')
		i += 1;
	if (str[i] == '+' || str[i] == '-')
	{
		operator = i;
		i += 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i += 1;
	}
	if (operator > -1 && str[operator] == '-')
		nb = -nb;
	return (nb);
}
