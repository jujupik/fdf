/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:04:07 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 20:04:11 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	t_map_change_view_mode(t_map *ptr_map, int new_view_mode)
{
	ptr_map->view_mode = new_view_mode;
	ptr_map->scaled_tile_size = create_t_vector2f((float)(ptr_map->tile_size.x),
		(float)(ptr_map->tile_size.y));
	ptr_map->zoom = -1.0f;
	ptr_map->offset = create_t_vector2i(0, 0);
	ptr_map->height_ratio = 5.5f;
}

void	t_map_change_height_ratio(t_map *ptr_map, float delta)
{
	ptr_map->height_ratio += delta;
	ptr_map->scaled_height_ratio = ptr_map->height_ratio * ptr_map->zoom;
}

void	t_map_change_zoom(t_map *ptr_map, float delta)
{
	int ratio;

	if (ptr_map->view_mode == ISOMETRIC)
		ratio = 2;
	else
		ratio = 1;
	if (ptr_map->zoom * delta <= 20.0f)
	{
		ptr_map->zoom *= delta;
		ptr_map->scaled_height_ratio = ptr_map->height_ratio * ptr_map->zoom;
		ptr_map->scaled_tile_size.x = ptr_map->zoom * ptr_map->tile_size.x;
		ptr_map->scaled_tile_size.y =
				ptr_map->zoom * ptr_map->tile_size.y / ratio;
	}
}

void	t_map_change_tile_offset(t_map *ptr_map, float delta_x, float delta_y)
{
	ptr_map->tile_offset.x += delta_x;
	ptr_map->tile_offset.y += delta_y;
}
