/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_t_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:08:53 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 14:08:54 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_T_MAP_H
# define FDF_T_MAP_H

typedef struct	s_map
{
	char		*path;
	t_vector2i	nb_elem;
	int			**height_tab;
	t_vector2i	**point_on_screen;
	t_vector2i	tile_size;
	t_vector2f	scaled_tile_size;
	t_vector2f	tile_offset;
	float		zoom;
	t_vector2i	offset;
	float		height_ratio;
	float		scaled_height_ratio;
	int			view_mode;
	t_color		floor;
	t_color		not_floor;
}				t_map;

t_map			create_t_map(char *p_path);
t_map			*malloc_t_map(char *p_path);
void			delete_t_map(t_map map);
void			free_t_map(t_map *ptr_map);
void			t_map_add_line(t_map *ptr_map, char *line);
void			draw_t_map(t_application *ptr_app, t_map *ptr_map);
void			t_map_calc_zoom(t_application *ptr_app, t_map *ptr_map);
void			t_map_calc_offset(t_application *ptr_app, t_map *ptr_map);
t_vector2i		convert_world_to_screen(t_map *ptr_map, int x, int y,
					int height);
void			t_map_change_view_mode(t_map *ptr_map, int new_view_mode);
void			t_map_calc_data(t_application *ptr_app, t_map *ptr_map);
void			t_map_change_height_ratio(t_map *ptr_map, float delta);
void			t_map_change_zoom(t_map *ptr_map, float delta);
void			t_map_calc_moving_delta(t_map *ptr_map);
void			create_point_on_screen(t_map *ptr_map);
void			reset_point_on_screen(t_map *ptr_map);
void			t_map_change_tile_offset(t_map *ptr_map, float delta_x,
					float delta_y);
void			t_map_set_color(t_map *ptr_map, int color_num, char *argv);

#endif
