/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_application.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:47:11 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 16:48:33 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			clear_screen(t_application *app)
{
	t_color	background;
	int		nb_pixel;
	int		i;
	int		pixel;

	i = 0;
	background = create_t_color(25, 25, 25, 255);
	nb_pixel = app->size.x * app->size.y;
	while (i < nb_pixel)
	{
		pixel = i * 4;
		app->pixels[pixel + B_COMP] = background.b;
		app->pixels[pixel + G_COMP] = background.g;
		app->pixels[pixel + R_COMP] = background.r;
		i++;
	}
}

void			render_screen(t_application *app)
{
	int	ret;

	ret = mlx_put_image_to_window(app->mlx_ptr, app->win_ptr,
		app->img_ptr, 0, 0);
	if (ret == 0)
		error_exit(1, "Can't render screen");
}

BOOL			is_point_on_screen(t_application *ptr_app, t_vector2i point)
{
	if (point.x < 0 || point.x >= ptr_app->size.x || point.y < 0 ||
		point.y >= ptr_app->size.y)
		return (FALSE);
	return (TRUE);
}
