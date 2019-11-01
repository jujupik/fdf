/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_define.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:51:09 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 13:51:12 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DEFINE_H
# define FDF_DEFINE_H

# define ORTHOGONAL 0
# define ISOMETRIC 1
# define MOVING_ORTHOGONAL 2
# define MOVING_ISOMETRIC 3

# define B_COMP 0
# define G_COMP 1
# define R_COMP 2
# define A_COMP 3

# define ARG_ERROR "Bad argument format -> try ./fdf [MAP_NAME] --c1 [Color] --c2 [Color] --mode [MODE]\nMode available : ORTHOGONAL / ISOMETRIC / MOVING_ORTHOGONAL / MOVING_ISOMETRIC"

#endif
