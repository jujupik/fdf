/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:45:27 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/28 20:48:27 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	ft_isalpha(int c)
{
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
		return (FALSE);
	return (TRUE);
}

BOOL	ft_strisalpha(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
