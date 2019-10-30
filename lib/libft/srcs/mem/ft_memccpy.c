/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:02:20 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/28 19:58:17 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	unsigned int	i;
	char			*destp;
	const char		*srcp;

	i = 0;
	destp = (char *)dest;
	srcp = (const char *)src;
	while (i < len)
	{
		destp[i] = srcp[i];
		if (srcp[i] == (char)c)
			return (destp + i + 1);
		i++;
	}
	return (NULL);
}
