/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:47:11 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 16:48:33 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	t_color_add(t_color a, t_color b)
{
	t_color result;

	result.r = a.r + b.r;
	result.g = a.g + b.g;
	result.b = a.b + b.b;
	result.a = (a.a + b.a) / 2;
	return (result);
}

t_color	t_color_substract(t_color a, t_color b)
{
	t_color result;

	result.r = a.r - b.r;
	result.g = a.g - b.g;
	result.b = a.b - b.b;
	result.a = (a.a + b.a) / 2;
	return (result);
}

t_color	t_color_mult(t_color a, t_color b)
{
	t_color result;

	result.r = a.r * b.r;
	result.g = a.g * b.g;
	result.b = a.b * b.b;
	result.a = (a.a + b.a) / 2;
	return (result);
}

t_color	t_color_divide(t_color a, t_color b)
{
	t_color result;

	result.r = a.r / b.r;
	result.g = a.g / b.g;
	result.b = a.b / b.b;
	result.a = (a.a + b.a) / 2;
	return (result);
}
