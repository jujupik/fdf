/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 18:24:26 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/31 18:40:45 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*tab;
	size_t			i;

	i = 0;
	tab = (unsigned char *)str;
	while (i < len)
	{
		if (tab[i] == (unsigned char)c)
			return (&tab[i]);
		i++;
	}
	return (NULL);
}
