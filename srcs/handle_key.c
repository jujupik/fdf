/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:30:44 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 20:30:49 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_fdf(t_application *ptr_app, t_map *ptr_map)
{
	clear_screen(ptr_app);
	draw_t_map(ptr_app, ptr_map);
	render_screen(ptr_app);
}

static void	handle_key_one(int key, t_map *ptr_map)
{
	if (key == K1_KEY)
		t_map_change_view_mode(ptr_map, ORTHOGONAL);
	else if (key == K2_KEY)
		t_map_change_view_mode(ptr_map, ISOMETRIC);
	else if (key == K3_KEY)
		t_map_change_view_mode(ptr_map, MOVING_ORTHOGONAL);
	else if (key == K4_KEY)
		t_map_change_view_mode(ptr_map, MOVING_ISOMETRIC);
	else if (key == ESC_KEY)
		exit(0);
}

static void	handle_key_two(int key, t_map *ptr_map)
{
	if (key == NKMN_KEY)
		t_map_change_height_ratio(ptr_map, -0.25f);
	else if (key == NKPL_KEY)
		t_map_change_height_ratio(ptr_map, +0.25f);
	else if (key == W_KEY)
		t_map_change_tile_offset(ptr_map, 0, -0.25f);
	else if (key == S_KEY)
		t_map_change_tile_offset(ptr_map, 0, +0.25f);
	else if (key == A_KEY)
		t_map_change_tile_offset(ptr_map, -0.25f, 0);
	else if (key == D_KEY)
		t_map_change_tile_offset(ptr_map, +0.25f, 0);
	else if (key == Q_KEY)
		t_map_change_zoom(ptr_map, 0.8f);
	else if (key == E_KEY)
		t_map_change_zoom(ptr_map, 1.2f);
}

int			handle_key(int key, void *param)
{
	t_application	*ptr_app;
	t_map			*ptr_map;

	ptr_app = ((void **)param)[0];
	ptr_map = ((void **)param)[1];
	handle_key_one(key, ptr_map);
	handle_key_two(key, ptr_map);
	draw_fdf(ptr_app, ptr_map);
	return (0);
}

void		parse_argv(int argc, char **argv, t_map *ptr_map)
{
	int				i;

	i = 2;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--c1") == 0)
			t_map_set_color(ptr_map, 1, argv[i + 1]);
		else if (ft_strcmp(argv[i], "--c2") == 0)
			t_map_set_color(ptr_map, 2, argv[i + 1]);
		else if (ft_strcmp(argv[i], "--mode") == 0)
		{
			if (ft_strcmp(argv[i + 1], "ORTHOGONAL") == 0)
				t_map_change_view_mode(ptr_map, ORTHOGONAL);
			if (ft_strcmp(argv[i + 1], "ISOMETRIC") == 0)
				t_map_change_view_mode(ptr_map, ISOMETRIC);
		}
		else
			print_usage();
		i += 2;
	}
}
