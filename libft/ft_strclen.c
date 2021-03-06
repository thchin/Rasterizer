/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thchin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:59:05 by thchin            #+#    #+#             */
/*   Updated: 2016/11/23 12:01:22 by thchin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strclen(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i += 1;
	return (i);
}
