/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:37:47 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 13:37:49 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_exit(int nb, char *str)
{
	ft_putstr("Error [");
	ft_putnbr(nb);
	ft_putstr("] : ");
	ft_putstr(str);
	ft_putstr("\n");
	exit(nb);
}
