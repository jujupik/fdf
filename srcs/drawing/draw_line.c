/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:47:11 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 16:48:33 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	true_draw_line_fade(t_application *app, t_pixel start, t_pixel end)
{
	int				index;
	t_vector2i		pixel;
	t_vector2i_list	pixels;
	t_color			pixel_color;
	t_color			delta;

	pixel_color = start.color;
	pixels = calc_line_2d(start.pos, end.pos);
	if (is_t_vector2i_equal(t_vector2i_list_at(&pixels, 0), start.pos) == FALSE)
		swap_t_color(&start.color, &end.color);
	delta = t_color_divide_by_int(t_color_substract(end.color, start.color),
		pixels.len);
	index = 0;
	while (index < pixels.len)
	{
		pixel = t_vector2i_list_at(&pixels, index);
		put_pixel(app, pixel, pixel_color);
		pixel_color = t_color_add(pixel_color, delta);
		index++;
	}
	delete_t_vector2i_list(pixels);
}

void		draw_line(t_application *ptr_app, t_pixel start, t_pixel end)
{
	draw_line_fade(ptr_app, start, end);
}

void		draw_line_fade(t_application *ptr_app, t_pixel start, t_pixel end)
{
	if (is_point_on_screen(ptr_app, start.pos) == TRUE ||
		is_point_on_screen(ptr_app, end.pos) == TRUE ||
		(start.pos.x < 0 && end.pos.x > 0 &&
		((start.pos.y > 0 && start.pos.y < ptr_app->size.x) ||
		(end.pos.y > 0 && end.pos.y < ptr_app->size.y))) ||
		(start.pos.x > 0 && end.pos.x < 0 &&
		((start.pos.y > 0 && start.pos.y < ptr_app->size.x) ||
		(end.pos.y > 0 && end.pos.y < ptr_app->size.y))) ||
		(start.pos.y < 0 && end.pos.x > 0 &&
		((start.pos.x > 0 && start.pos.x < ptr_app->size.x) ||
		(end.pos.x > 0 && end.pos.x < ptr_app->size.x))) ||
		(start.pos.y > 0 && end.pos.x < 0 &&
		((start.pos.x > 0 && start.pos.x < ptr_app->size.x) ||
		(end.pos.x > 0 && end.pos.x < ptr_app->size.x))))
		true_draw_line_fade(ptr_app, start, end);
}
