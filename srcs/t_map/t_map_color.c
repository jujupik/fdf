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

void			t_map_set_color(t_map *ptr_map, int color_num, char *argv)
{
	t_color		color;
	char		**tab;
	int			len;
	int			i;

	tab = ft_strsplit(argv, ' ');
	len = ft_tab_len(tab);
	if (len != 3 && len != 4)
		error_exit(12, "Bad composition in color argument");
	i = 0;
	while (i < len)
	{
		if (ft_strisdigit(tab[i]) == FALSE)
			error_exit(16, "Color not valid");
		i++;
	}
	color = create_t_color(ft_atoi(tab[0]), ft_atoi(tab[1]),
			ft_atoi(tab[2]), (len == 3 ? 255 : ft_atoi(tab[3])));
	if (color_num == 1)
		ptr_map->floor = color;
	else if (color_num == 2)
		ptr_map->not_floor = color;
}
