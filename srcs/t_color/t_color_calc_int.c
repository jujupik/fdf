/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color_calc_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:47:11 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 16:48:33 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	t_color_add_int(t_color a, int delta)
{
	t_color result;

	result.r = a.r + delta;
	result.g = a.g + delta;
	result.b = a.b + delta;
	result.a = a.a;
	return (result);
}

t_color	t_color_substract_int(t_color a, int delta)
{
	t_color result;

	result.r = a.r - delta;
	result.g = a.g - delta;
	result.b = a.b - delta;
	result.a = a.a;
	return (result);
}

t_color	t_color_mult_by_int(t_color a, int delta)
{
	t_color result;

	result.r = a.r * delta;
	result.g = a.g * delta;
	result.b = a.b * delta;
	result.a = a.a;
	return (result);
}

t_color	t_color_divide_by_int(t_color a, int delta)
{
	t_color result;

	result.r = a.r / delta;
	result.g = a.g / delta;
	result.b = a.b / delta;
	result.a = a.a;
	return (result);
}
