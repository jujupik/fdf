/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:28:31 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/28 20:00:13 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned int	i;
	char			*destp;
	const char		*srcp;

	destp = (char *)dest;
	srcp = (const char *)src;
	if (src == dest)
		return (dest);
	if (src < dest)
	{
		i = len;
		while (i-- > 0)
			destp[i] = srcp[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			destp[i] = srcp[i];
			i++;
		}
	}
	return (dest);
}
