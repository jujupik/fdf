/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:47:11 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 16:48:33 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			draw_map_tile_south(t_application *ptr_app, t_map *ptr_map,
	t_vector2i pos)
{
	t_vector2i	actual;
	t_color		colors[2];
	t_pixel		pixel[2];
	int			height[2];

	colors[0] = create_t_color(255, 0, 0, 255);
	colors[1] = create_t_color(0, 255, 255, 255);
	height[0] = ptr_map->height_tab[pos.y][pos.x];
	actual = convert_world_to_screen(ptr_map, pos.x, pos.y, height[0]);
	pixel[0] = create_t_pixel(actual, (height[0] == 0 ? colors[0] : colors[1]));
	put_pixel(ptr_app, actual, colors[0]);
	if (pos.y + 1 < ptr_map->nb_elem.y)
	{
		height[1] = ptr_map->height_tab[pos.y + 1][pos.x];
		actual = convert_world_to_screen(ptr_map, pos.x, pos.y + 1, height[1]);
		pixel[1] = create_t_pixel(actual,
			(height[1] == 0 ? colors[0] : colors[1]));
		draw_line_fade(ptr_app, pixel[0], pixel[1]);
	}
}

static void			draw_map_tile_east(t_application *ptr_app, t_map *ptr_map,
	t_vector2i pos)
{
	t_vector2i	actual;
	t_color		colors[2];
	t_pixel		pixel[2];
	int			height[2];

	colors[0] = create_t_color(255, 0, 0, 255);
	colors[1] = create_t_color(0, 255, 255, 255);
	height[0] = ptr_map->height_tab[pos.y][pos.x];
	actual = convert_world_to_screen(ptr_map, pos.x, pos.y, height[0]);
	pixel[0] = create_t_pixel(actual, (height[0] == 0 ? colors[0] : colors[1]));
	put_pixel(ptr_app, actual, colors[1]);
	if (pos.x + 1 < ptr_map->nb_elem.x)
	{
		height[1] = ptr_map->height_tab[pos.y][pos.x + 1];
		actual = convert_world_to_screen(ptr_map, pos.x + 1, pos.y, height[1]);
		pixel[1] = create_t_pixel(actual,
			(height[1] == 0 ? colors[0] : colors[1]));
		draw_line_fade(ptr_app, pixel[0], pixel[1]);
	}
}

void				draw_t_map(t_application *ptr_app, t_map *ptr_map)
{
	t_vector2i pos;

	reset_point_on_screen(ptr_map);
	t_map_calc_data(ptr_app, ptr_map);
	pos.x = 0;
	while (pos.x < ptr_map->nb_elem.x)
	{
		pos.y = 0;
		while (pos.y < ptr_map->nb_elem.y)
		{
			draw_map_tile_east(ptr_app, ptr_map, pos);
			draw_map_tile_south(ptr_app, ptr_map, pos);
			pos.y++;
		}
		pos.x++;
	}
}
