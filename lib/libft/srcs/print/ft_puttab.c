/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:36:43 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 13:36:45 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **tab)
{
	int	i;

	if (tab == NULL)
		error_exit(4, "No char tab to print");
	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		i++;
	}
}
