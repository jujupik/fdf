/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intstr_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:31:28 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 13:31:29 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_int_str_new(int size)
{
	int	i;
	int	*result;

	result = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}
