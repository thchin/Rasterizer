/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:43:31 by thchin            #+#    #+#             */
/*   Updated: 2016/11/16 18:27:04 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	exp;

	exp = 1;
	if (n < 0)
		ft_putchar_fd('-', fd);
	else
		n = -n;
	while (n / exp < -9)
		exp *= 10;
	while (exp > 0)
	{
		ft_putchar_fd('0' - (n / exp), fd);
		n %= exp;
		exp /= 10;
	}
}
