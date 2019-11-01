/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttab_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:33:02 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 13:33:04 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_inttab_cpy(int **dest, int **src)
{
	int	i;

	if (src == NULL)
		error_exit(1, "Src is null in ft_inttab_cpy");
	if (dest == NULL)
		error_exit(1, "Dest is null in ft_inttab_cpy");
	i = 0;
	while (src[i] != NULL)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = NULL;
}
