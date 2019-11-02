/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_t_vector2i_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:13:48 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 20:13:51 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector2i	**new_t_vector2i_tab(size_t size)
{
	t_vector2i	**result;
	size_t		i;

	result = (t_vector2i **)malloc(sizeof(t_vector2i *) * (size + 1));
	if (result == NULL)
		error_exit(109, "Can't malloc a t_vector2i **");
	i = 0;
	while (i < size + 1)
	{
		result[i] = NULL;
		i++;
	}
	return (result);
}

t_vector2i	*new_t_vector2i_array(size_t size)
{
	t_vector2i	*result;
	size_t		i;

	result = (t_vector2i *)malloc(sizeof(t_vector2i) * size);
	if (result == NULL)
		error_exit(110, "Can't malloc a t_vector2i *");
	i = 0;
	while (i < size)
	{
		result[i] = create_t_vector2i(0, 0);
		i++;
	}
	return (result);
}

void		copy_t_vector2i_tab(t_vector2i **dest, t_vector2i **src)
{
	int i;

	i = 0;
	while (src[i] != NULL)
	{
		dest[i] = src[i];
		i++;
	}
}
