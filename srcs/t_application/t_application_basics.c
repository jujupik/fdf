/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_application_basics.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:47:11 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 16:48:33 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_application	create_t_application(char *prog_name, int width, int height)
{
	t_application	result;

	result.mlx_ptr = NULL;
	result.win_ptr = NULL;
	result.mlx_ptr = mlx_init();
	if (result.mlx_ptr == NULL)
		error_exit(1, "Can't create a window");
	result.win_ptr = mlx_new_window(result.mlx_ptr, width, height, prog_name);
	result.size = create_t_vector2i(width, height);
	result.img_ptr = mlx_new_image(result.mlx_ptr, width, height);
	result.pixels = (unsigned char *)(mlx_get_data_addr(result.img_ptr,
		&(result.bpp), &(result.line_size), &(result.endian)));
	return (result);
}

t_application	*malloc_t_application(char *prog_name, int width, int height)
{
	t_application	*result;

	result = (t_application *)malloc(sizeof(t_application));
	if (result == NULL)
		error_exit(1, "Error malloc_t_application");
	*result = create_t_application(prog_name, width, height);
	return (result);
}

void			delete_t_application(t_application app)
{
	if (mlx_destroy_image(app.mlx_ptr, app.img_ptr) == 0)
		error_exit(1, "Can't destroy image");
	if (mlx_destroy_window(app.mlx_ptr, app.win_ptr) == 0)
		error_exit(1, "Can't destroy a window");
	app.pixels = NULL;
	app.img_ptr = NULL;
	app.mlx_ptr = NULL;
	app.win_ptr = NULL;
}

void			free_t_application(t_application *app)
{
	delete_t_application(*app);
	free(app);
}
