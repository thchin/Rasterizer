/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 13:51:35 by thchin            #+#    #+#             */
/*   Updated: 2016/12/22 13:54:16 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_nblen_base(const char *str, const char *base)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (-1 == ft_check_char(str[i], base))
			return (i);
		i += 1;
	}
	return (i);
}
