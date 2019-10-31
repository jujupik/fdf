/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:47:42 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 20:47:46 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		convert_t_color(t_color color)
{
	int *tmp;

	tmp = (int *)(&color.r);
	return (*tmp);
}

void	swap_t_color(t_color *a, t_color *b)
{
	t_color tmp_color;

	tmp_color = *a;
	*a = *b;
	*b = tmp_color;
}
