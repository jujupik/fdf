/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:02:06 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 20:02:15 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	t_map_calc_zoom(t_application *ptr_app, t_map *ptr_map)
{
	t_vector2i	points[4];
	int			value[4];
	t_vector2i	screen_size;
	float		ratio[2];

	ptr_map->zoom = 1.0f;
	points[0] = convert_world_to_screen(ptr_map, -1, -1, 0);
	points[1] = convert_world_to_screen(ptr_map, ptr_map->nb_elem.x, -1, 0);
	points[2] = convert_world_to_screen(ptr_map, -1, ptr_map->nb_elem.y, 0);
	points[3] = convert_world_to_screen(ptr_map, ptr_map->nb_elem.x,
	ptr_map->nb_elem.y, 0);
	value[0] = ft_min(4, points[0].x, points[1].x, points[2].x, points[3].x);
	value[1] = ft_max(4, points[0].x, points[1].x, points[2].x, points[3].x);
	value[2] = ft_min(4, points[0].y, points[1].y, points[2].y, points[3].y);
	value[3] = ft_max(4, points[0].y, points[1].y, points[2].y, points[3].y);
	screen_size.x = value[1] - value[0];
	screen_size.y = value[3] - value[2];
	ratio[0] = ptr_app->size.x / (float)(screen_size.x);
	ratio[1] = ptr_app->size.y / (float)(screen_size.y);
	ptr_map->zoom = (ratio[0] < ratio[1] ? ratio[0] : ratio[1]);
	ptr_map->scaled_tile_size.x = ptr_map->zoom * ptr_map->tile_size.x;
	ptr_map->scaled_tile_size.y = ptr_map->zoom * ptr_map->tile_size.y /
		(ptr_map->view_mode == ISOMETRIC ? 2 : 1);
	ptr_map->scaled_height_ratio = ptr_map->height_ratio * ptr_map->zoom;
}

void	t_map_calc_offset(t_application *ptr_app, t_map *ptr_map)
{
	int			value[2];
	t_vector2i	points[4];
	int			reste_x;
	int			reste_y;

	value[0] = ptr_map->nb_elem.x - 1;
	value[1] = ptr_map->nb_elem.y - 1;
	points[0] = convert_world_to_screen(ptr_map, 0, 0, 0);
	points[1] = convert_world_to_screen(ptr_map, value[0], 0, 0);
	points[2] = convert_world_to_screen(ptr_map, 0, value[1], 0);
	points[3] = convert_world_to_screen(ptr_map, value[0], value[1], 0);
	reste_x = ptr_app->size.x - points[1].x - points[2].x;
	reste_y = ptr_app->size.y - points[3].y - points[0].y;
	ptr_map->offset.x = reste_x / 2;
	ptr_map->offset.y = reste_y / 2;
	ptr_map->point_on_screen[0][0] = create_t_vector2i(-1, -1);
	ptr_map->point_on_screen[value[0]][0] = create_t_vector2i(-1, -1);
	ptr_map->point_on_screen[0][value[1]] = create_t_vector2i(-1, -1);
	ptr_map->point_on_screen[value[0]][value[1]] = create_t_vector2i(-1, -1);
}

void	t_map_calc_data(t_application *ptr_app, t_map *ptr_map)
{
	if (ptr_map->zoom == -1)
	{
		t_map_calc_zoom(ptr_app, ptr_map);
		t_map_calc_offset(ptr_app, ptr_map);
	}
}
