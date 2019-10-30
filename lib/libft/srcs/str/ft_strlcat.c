/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:28:42 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/31 22:00:50 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	j = 0;
	i = ft_strlen(dst);
	while (src[j] != '\0' && i < (size - 1) && size != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	return (ft_strlen(src) + ft_strlen(dst) - j);
}
