/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pixel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:06:19 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 20:06:21 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	create_t_pixel(t_vector2i p_pos, t_color p_color)
{
	t_pixel result;

	result.pos = p_pos;
	result.color = p_color;
	return (result);
}

t_pixel	*malloc_t_pixel(t_vector2i p_pos, t_color p_color)
{
	t_pixel *result;

	result = (t_pixel *)malloc(sizeof(t_pixel));
	if (result == NULL)
		error_exit(1, "Can't malloc t_pixel.");
	*result = create_t_pixel(p_pos, p_color);
	return (result);
}

void	delete_t_pixel(t_pixel pixel)
{
	(void)pixel;
}

void	free_t_pixel(t_pixel *pixel)
{
	delete_t_pixel(*pixel);
	free(pixel);
}
