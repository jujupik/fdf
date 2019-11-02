/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:58:10 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 19:58:16 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	read_map_file(t_map *ptr_map)
{
	int		fd;
	char	*line;

	fd = open(ptr_map->path, O_RDONLY);
	if (fd < 0)
		error_exit(10, "Can't open a file");
	while (get_next_line(fd, &line) > 0)
	{
		if (line == NULL)
			error_exit(15, "Can't parse a line in file");
		t_map_add_line(ptr_map, line);
		if (line != NULL)
			free(line);
		line = NULL;
	}
	if (ptr_map->nb_elem.x == 0 || ptr_map->nb_elem.y == 0)
		error_exit(11, "No tile to draw in map file");
}

t_map		create_t_map(char *p_path)
{
	t_map	result;

	result.path = p_path;
	result.nb_elem = create_t_vector2i(0, 0);
	result.tile_size = create_t_vector2i(50, 50);
	result.scaled_tile_size = create_t_vector2f(
		(float)(result.tile_size.x),
		(float)(result.tile_size.y));
	result.offset = create_t_vector2i(0, 0);
	result.zoom = -1.0f;
	result.height_ratio = 5.5f;
	result.height_tab = NULL;
	read_map_file(&result);
	result.tile_offset = create_t_vector2f(((float)(result.nb_elem.x)
		- 1.0f) / 2.0f, ((float)(result.nb_elem.y) - 1.0f) / 2.0f);
	create_point_on_screen(&result);
	result.floor = create_t_color(255, 0, 0, 255);
	result.not_floor = create_t_color(0, 255, 255, 255);
	return (result);
}

t_map		*malloc_t_map(char *p_path)
{
	t_map	*result;

	result = (t_map *)malloc(sizeof(t_map));
	if (result == NULL)
		error_exit(104, "Can't malloc t_map");
	*result = create_t_map(p_path);
	return (result);
}

void		delete_t_map(t_map map)
{
	(void)map;
}

void		free_t_map(t_map *map)
{
	delete_t_map(*map);
	free(map);
}
