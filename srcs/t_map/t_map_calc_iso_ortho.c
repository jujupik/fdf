/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_calc_iso_ortho.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:47:11 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 16:48:33 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vector2i	calc_iso(t_map *ptr_map, int x, int y, int height)
{
	t_vector2i result;

	result.x = ((x - ptr_map->tile_offset.x) - (y - ptr_map->tile_offset.y))
	* ptr_map->scaled_tile_size.x + ptr_map->offset.x;
	result.y = ((x - ptr_map->tile_offset.x) + (y - ptr_map->tile_offset.y))
	* ptr_map->scaled_tile_size.y + ptr_map->offset.y
	- height * ptr_map->scaled_height_ratio;
	return (result);
}

static t_vector2i	calc_ortho(t_map *ptr_map, int x, int y, int height)
{
	t_vector2i result;

	result.x = (x - ptr_map->tile_offset.x) * ptr_map->scaled_tile_size.x
	+ ptr_map->offset.x;
	result.y = (y - ptr_map->tile_offset.y) * ptr_map->scaled_tile_size.y
	+ ptr_map->offset.y
	- height * ptr_map->scaled_height_ratio;
	return (result);
}

t_vector2i			convert_world_to_screen(t_map *ptr_map, int x, int y,
	int height)
{
	if (x < 0 || y < 0 || x >= ptr_map->nb_elem.x || y >= ptr_map->nb_elem.y)
	{
		if (ptr_map->view_mode == ISOMETRIC)
			return (calc_iso(ptr_map, x, y, height));
		else
			return (calc_ortho(ptr_map, x, y, height));
	}
	if (is_t_vector2i_equal(ptr_map->point_on_screen[x][y],
		create_t_vector2i(-1, -1)) == TRUE)
	{
		if (ptr_map->view_mode == ISOMETRIC)
			ptr_map->point_on_screen[x][y] = calc_iso(ptr_map, x, y, height);
		else
			ptr_map->point_on_screen[x][y] = calc_ortho(ptr_map, x, y, height);
	}
	return (ptr_map->point_on_screen[x][y]);
}
