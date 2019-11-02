/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:49:40 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/28 23:05:39 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (TRUE);
	return (FALSE);
}

BOOL	ft_strisalnum(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
