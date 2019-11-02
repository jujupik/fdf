/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:53:54 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/28 23:12:43 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (TRUE);
	return (FALSE);
}

BOOL	ft_strisprint(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isprint(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
