/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:30:44 by jrouchon          #+#    #+#             */
/*   Updated: 2019/10/31 20:30:49 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_usage(void)
{
	ft_putstr_fd(TEXT_ERROR, 2);
	ft_putstr_fd(USAGE, 2);
	ft_putstr_fd(MODE_CONTENT, 2);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_application	app;
	t_map			map;

	if (argc < 2 || argc % 2 != 0)
		print_usage();
	app = create_t_application("fdf", 1250, 1080, 15889);
	map = create_t_map(argv[1]);
	parse_argv(argc, argv, &map);
	draw_fdf(&app, &map);
	run_t_application(&app, NULL, handle_key, &map);
	return (0);
}
