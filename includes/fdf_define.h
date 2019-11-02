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

# define B_COMP 0
# define G_COMP 1
# define R_COMP 2
# define A_COMP 3

# define TEXT_ERROR "Bad argument format -> "
# define USAGE "try ./fdf [MAP_NAME] --c1 [Color] --c2 [Color] --mode [MODE]\n"
# define MODE_CONTENT "Mode available : ORTHOGONAL / ISOMETRIC\n"

#endif
