/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putinttab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:35:52 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 13:35:53 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putinttab(int **tab, int len)
{
	int	j;
	int	i;

	if (tab == NULL)
		error_exit(1, "No int tab to print");
	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (j < len)
		{
			if (j != 0)
				ft_putstr("\t");
			ft_putnbr(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
