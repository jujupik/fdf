/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:14:24 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 14:14:28 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_includes.h"
# include "fdf_event_define.h"
# include "fdf_define.h"

# include "fdf_vector.h"
# include "fdf_color.h"
# include "fdf_pixel.h"
# include "fdf_t_application.h"
# include "fdf_t_map.h"
# include "fdf_drawing.h"
# include "fdf_t_vector2i_list.h"
# include "fdf_algorithm.h"

void		draw_fdf(t_application *ptr_app, t_map *ptr_map);
int			handle_key(int key, void *param);
void		parse_argv(int argc, char **argv, t_map *ptr_map);
void		print_usage(char *msg);

#endif
