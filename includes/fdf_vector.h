/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vector.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:14:03 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 14:14:04 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_VECTOR_H
# define FDF_VECTOR_H

typedef struct	s_vector2i
{
	int	x;
	int	y;
}				t_vector2i;

t_vector2i		create_t_vector2i(int p_x, int p_y);
t_vector2i		*malloc_t_vector2i(int p_x, int p_y);
void			swap_t_vector2i(t_vector2i *a, t_vector2i *b);
t_vector2i		**new_t_vector2i_tab(size_t size);
t_vector2i		*new_t_vector2i_array(size_t size);
void			copy_t_vector2i_tab(t_vector2i **dest, t_vector2i **src);
BOOL			is_t_vector2i_equal(t_vector2i a, t_vector2i b);

typedef struct	s_vector2f
{
	float	x;
	float	y;
}				t_vector2f;

t_vector2f		create_t_vector2f(float p_x, float p_y);
t_vector2f		*malloc_t_vector2f(float p_x, float p_y);
void			swap_t_vector2f(t_vector2f *a, t_vector2f *b);
t_vector2f		**new_t_vector2f_tab(size_t size);
t_vector2f		*new_t_vector2f_array(size_t size);
void			copy_t_vector2f_tab(t_vector2f **dest, t_vector2f **src);
BOOL			is_t_vector2f_equal(t_vector2f a, t_vector2f b);

#endif
