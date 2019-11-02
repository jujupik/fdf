/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector2t_vector2i_list_basics.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:47:11 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 16:48:33 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector2i_list	create_t_vector2i_list(int p_line_len)
{
	t_vector2i_list	result;

	result.line_len = p_line_len;
	result.data = new_t_vector2i_tab(1);
	result.data[0] = new_t_vector2i_array(result.line_len);
	result.len = 0;
	result.max_len = result.line_len;
	return (result);
}

t_vector2i_list	*malloc_t_vector2i_list(int p_line_len)
{
	t_vector2i_list *result;

	result = (t_vector2i_list *)malloc(sizeof(t_vector2i_list));
	if (result == NULL)
		error_exit(101, "Can't malloc t_vector2i_list");
	*result = create_t_vector2i_list(p_line_len);
	return (result);
}

void			delete_t_vector2i_list(t_vector2i_list list)
{
	int i;

	i = 0;
	if (list.data == NULL)
		return ;
	while (list.data[i] != NULL)
	{
		free(list.data[i]);
		i++;
	}
	free(list.data);
}

void			free_t_vector2i_list(t_vector2i_list *list)
{
	delete_t_vector2i_list(*list);
	free(list);
}
