/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:55:17 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 13:55:19 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DRAWING_H
# define FDF_DRAWING_H

void	put_pixel(t_application *application, t_vector2i pos, t_color color);
void	draw_line(t_application *application, t_pixel start, t_pixel end);
void	draw_point(t_application *application, t_pixel point, int size);
void	draw_line_fade(t_application *app, t_pixel start, t_pixel end);
#endif
