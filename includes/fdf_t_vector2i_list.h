/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_t_vector2i_list.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:11:30 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 14:11:32 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_T_VECTOR2I_LIST_H
# define FDF_T_VECTOR2I_LIST_H

typedef struct	s_vector2_int_list
{
	t_vector2i	**data;
	int			len;
	int			max_len;
	int			line_len;
}				t_vector2i_list;

t_vector2i_list	create_t_vector2i_list(int p_line_len);
t_vector2i_list	*malloc_t_vector2i_list(int p_line_len);
void			delete_t_vector2i_list(t_vector2i_list list);
void			free_t_vector2i_list(t_vector2i_list *list);
void			t_vector2i_list_add(t_vector2i_list *list, t_vector2i to_add);
t_vector2i		t_vector2i_list_at(t_vector2i_list *list, size_t index);

#endif
