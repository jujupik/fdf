/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:24:01 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 13:24:02 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int nb_number, ...)
{
	int		result;
	int		tmp;
	int		i;
	va_list	params;

	va_start(params, nb_number);
	result = INT_MIN;
	i = 0;
	while (i < nb_number)
	{
		tmp = va_arg(params, int);
		if (tmp > result)
			result = tmp;
		i++;
	}
	va_end(params);
	return (result);
}
