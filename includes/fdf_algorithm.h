/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_algorithm.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:51:57 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 13:51:59 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_ALGORITHM_H
# define FDF_ALGORITHM_H

int					generate_nbr(int min, int max);
t_vector2i_list		calc_line_2d(t_vector2i point_a, t_vector2i point_b);

#endif
