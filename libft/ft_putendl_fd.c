/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:42:49 by thchin            #+#    #+#             */
/*   Updated: 2016/11/16 18:26:29 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	unsigned int	len;
	char			c;

	c = '\n';
	len = ft_strlen((char *)s);
	write(fd, s, len);
	write(fd, &c, 1);
}
