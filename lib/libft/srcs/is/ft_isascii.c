/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:40:13 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/28 20:51:44 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (TRUE);
	return (FALSE);
}

BOOL	ft_strisascii(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isascii(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
