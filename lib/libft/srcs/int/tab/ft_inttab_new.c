/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttab_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:33:49 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 13:33:53 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_inttab_new(int size)
{
	int	i;
	int	**result;

	result = (int **)malloc(sizeof(int *) * (size + 1));
	if (result == NULL)
		error_exit(1, "Can't malloc a int **");
	i = 0;
	while (i < size + 1)
	{
		result[i] = NULL;
		i++;
	}
	return (result);
}
