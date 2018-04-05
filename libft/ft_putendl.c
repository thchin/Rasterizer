/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:49:56 by thchin            #+#    #+#             */
/*   Updated: 2016/11/16 18:26:18 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl(char const *s)
{
	unsigned int	len;
	char			c;

	c = '\n';
	len = ft_strlen(s);
	write(1, s, len);
	write(1, &c, 1);
}
