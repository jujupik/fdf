/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:05:47 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 20:05:50 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_point_on_screen(t_map *ptr_map)
{
	int	i;

	ptr_map->point_on_screen = new_t_vector2i_tab(ptr_map->nb_elem.x);
	i = 0;
	while (i < ptr_map->nb_elem.x)
	{
		ptr_map->point_on_screen[i] = new_t_vector2i_array(ptr_map->nb_elem.y);
		i++;
	}
}

void	reset_point_on_screen(t_map *ptr_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < ptr_map->nb_elem.x)
	{
		j = 0;
		while (j < ptr_map->nb_elem.y)
		{
			ptr_map->point_on_screen[i][j] = create_t_vector2i(-1, -1);
			j++;
		}
		i++;
	}
}

void	t_map_add_line(t_map *ptr_map, char *line)
{
	char	**tab;
	int		len;
	int		**tmp;

	if (ptr_map == NULL && line == NULL)
		error_exit(24, "Error in t_map_add_line");
	tab = ft_strsplit(line, ' ');
	len = ft_tab_len(tab);
	if (ptr_map->nb_elem.x == 0)
		ptr_map->nb_elem.x = len;
	if (ptr_map->nb_elem.x != len)
		error_exit(1, "Bad line in ptr_map");
	ptr_map->nb_elem.y++;
	tmp = ft_inttab_new(ptr_map->nb_elem.y);
	if (ptr_map->height_tab != NULL)
	{
		ft_inttab_cpy(tmp, ptr_map->height_tab);
		free(ptr_map->height_tab);
	}
	ptr_map->height_tab = tmp;
	ptr_map->height_tab[ptr_map->nb_elem.y - 1] = ft_intparse_tab(tab);
	ft_tab_free(tab);
}
