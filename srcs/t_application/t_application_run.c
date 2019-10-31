/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_application_run.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:47:11 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 16:48:33 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	run_t_application(t_application *app, int funct_ptr(int, void *),
	void *param)
{
	void *ptr_strange[2];

	ptr_strange[0] = app;
	ptr_strange[1] = param;
	if (funct_ptr != NULL)
		mlx_hook(app->win_ptr, KEYPRESS, KEYPRESSMASK, funct_ptr, ptr_strange);
	mlx_loop(app->mlx_ptr);
	return (0);
}
