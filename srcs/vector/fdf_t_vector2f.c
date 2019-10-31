/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_t_vector2f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:12:32 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 20:12:34 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector2f	create_t_vector2f(float p_x, float p_y)
{
	t_vector2f result;

	result.x = p_x;
	result.y = p_y;
	return (result);
}

t_vector2f	*malloc_t_vector2f(float p_x, float p_y)
{
	t_vector2f	*result;

	result = (t_vector2f *)malloc(sizeof(t_vector2f));
	if (result == NULL)
		error_exit(32, "Can't malloc a t_vector2f");
	*result = create_t_vector2f(p_x, p_y);
	return (result);
}

void		swap_t_vector2f(t_vector2f *a, t_vector2f *b)
{
	ft_swap_float(&(a->x), &(b->x));
	ft_swap_float(&(a->y), &(b->y));
}

BOOL		is_t_vector2f_equal(t_vector2f a, t_vector2f b)
{
	if (a.x == b.x && a.y == b.y)
		return (TRUE);
	else
		return (FALSE);
}
