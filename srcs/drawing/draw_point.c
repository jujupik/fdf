/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:26:50 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 20:27:48 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_point(t_application *app, t_pixel point, int size)
{
	t_vector2i	pixel;
	int			i;
	int			j;

	i = -size / 2;
	while (i <= size / 2)
	{
		j = -size / 2;
		while (j <= size / 2)
		{
			pixel.x = point.pos.x + i;
			pixel.y = point.pos.y + j;
			put_pixel(app, pixel, point.color);
			j++;
		}
		i++;
	}
}
