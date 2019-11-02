/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:42:31 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/28 20:49:35 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	ft_isnum(int c)
{
	if ((c < '0' || c > '9') && c != '-' && c != '+')
		return (FALSE);
	return (TRUE);
}

BOOL	ft_strisnum(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isnum(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
