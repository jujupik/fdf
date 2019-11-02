/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector2i_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:47:11 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 16:48:33 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			t_vector2i_list_add(t_vector2i_list *list, t_vector2i to_add)
{
	t_vector2i	**tmp;
	int			nb_du_null;
	int			nb_line;
	int			nb_index;

	if (list->data == NULL)
		error_exit(5, "No data in t_vector2i_list");
	nb_du_null = list->max_len / list->line_len;
	if (list->len == list->max_len - 1)
	{
		tmp = list->data;
		list->data = new_t_vector2i_tab(nb_du_null + 1);
		copy_t_vector2i_tab(list->data, tmp);
		list->data[nb_du_null] = new_t_vector2i_array(list->line_len);
		list->max_len += list->line_len;
		free(tmp);
	}
	nb_line = nb_du_null - 1;
	nb_index = list->len - (nb_line * list->line_len);
	list->data[nb_line][nb_index] = to_add;
	list->len++;
}

t_vector2i		t_vector2i_list_at(t_vector2i_list *list, size_t index)
{
	int nb_line;
	int elem;

	if ((int)index >= list->len)
		return (create_t_vector2i(-1, -1));
	nb_line = index / list->line_len;
	elem = index - (nb_line * list->line_len);
	return (list->data[nb_line][elem]);
}
