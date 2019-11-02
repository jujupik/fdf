/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color_basics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:47:11 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 16:48:33 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	create_t_color(float p_r, float p_g, float p_b, float p_a)
{
	t_color	result;

	result.r = p_r;
	result.g = p_g;
	result.b = p_b;
	result.a = p_a;
	return (result);
}

t_color	*malloc_t_color(float p_r, float p_g, float p_b, float p_a)
{
	t_color	*result;

	result = (t_color *)malloc(sizeof(t_color));
	if (result == NULL)
		error_exit(103, "Can't malloc t_color");
	*result = create_t_color(p_r, p_g, p_b, p_a);
	return (result);
}

void	delete_t_color(t_color color)
{
	(void)color;
}

void	free_t_color(t_color *color)
{
	delete_t_color(*color);
	free(color);
}
