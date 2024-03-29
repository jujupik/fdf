/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:47:11 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 16:48:33 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		calc_steep(BOOL *steep, t_vector2i *a, t_vector2i *b)
{
	if (ft_abs(b->y - a->y) > ft_abs(b->x - a->x))
		*steep = TRUE;
	else
		*steep = FALSE;
	if (*steep == TRUE)
	{
		ft_swap_int(&(a->x), &(a->y));
		ft_swap_int(&(b->x), &(b->y));
	}
	if (a->x > b->x)
		swap_t_vector2i(a, b);
}

static void		calc_path(BOOL steep, t_vector2i_list *result,
	t_vector2i a, t_vector2i b)
{
	float		delta_x;
	float		delta_y;
	float		error;
	t_vector2i	pos;
	int			y_step;

	delta_x = b.x - a.x;
	delta_y = ft_abs(b.y - a.y);
	error = delta_x / 2.0f;
	pos = a;
	y_step = (a.y < b.y) ? 1 : -1;
	while (pos.x <= b.x)
	{
		if (steep == TRUE)
			t_vector2i_list_add(result, create_t_vector2i(pos.y, pos.x));
		else
			t_vector2i_list_add(result, create_t_vector2i(pos.x, pos.y));
		error -= delta_y;
		if (error < 0)
		{
			pos.y += y_step;
			error += delta_x;
		}
		pos.x++;
	}
}

t_vector2i_list	calc_line_2d(t_vector2i a, t_vector2i b)
{
	t_vector2i_list	result;
	BOOL			steep;

	result = create_t_vector2i_list(500);
	calc_steep(&steep, &a, &b);
	calc_path(steep, &result, a, b);
	return (result);
}
