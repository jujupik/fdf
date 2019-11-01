/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_t_application.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:03:43 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 14:03:45 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_T_APPLICATION_H
# define FDF_T_APPLICATION_H

typedef struct	s_application
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_vector2i		size;
	void			*img_ptr;
	unsigned char	*pixels;
	int				bpp;
	int				line_size;
	int				endian;

}				t_application;

t_application	create_t_application(char *prog_name, int width, int height, int seed);
t_application	*malloc_t_application(char *prog_name, int width, int height, int seed);
void			delete_t_application(t_application app);
void			free_t_application(t_application *ptr_app);
void			clear_screen(t_application *ptr_app);
void			render_screen(t_application *ptr_app);
BOOL			is_point_on_screen(t_application *ptr_app, t_vector2i point);
// void			set_control_t_application(t_application *app, int funct_ptr(int, void *),
// 	void *param);
// void			set_loop_t_application(t_application *app, int funct_ptr_hook(void *),
// 	void *param);
// int				run_t_application(t_application *app);
int	run_t_application(t_application *app,
	int funct_ptr_loop(void *), int funct_ptr_control(int, void *),
	void *param);

#endif
