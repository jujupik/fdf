/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:26:50 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/28 20:32:49 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	lastc;
	char	*pstr;

	lastc = (char)c;
	pstr = (char *)str;
	while (*pstr != '\0')
		pstr++;
	while (*pstr != lastc)
	{
		if (pstr == str)
			return (0);
		pstr--;
	}
	return ((char *)pstr);
}
