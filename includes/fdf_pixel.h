/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pixel.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:59:58 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 13:59:59 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PIXEL_H
# define FDF_PIXEL_H

typedef struct	s_pixel
{
	t_vector2i	pos;
	t_color		color;
}				t_pixel;

t_pixel			create_t_pixel();
t_pixel			*malloc_t_pixel();
void			delete_t_pixel();
void			free_t_pixel();

#endif
