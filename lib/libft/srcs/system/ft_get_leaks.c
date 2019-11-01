/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_leaks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:38:27 by jrouchon          #+#    #+#             */
/*   Updated: 2019/11/01 13:38:28 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_leaks(char *prog_name, char *msg)
{
	char	*command;
	char	*tmp;

	tmp = ft_strdup("leaks ");
	command = ft_strjoin(tmp, prog_name);
	free(tmp);
	tmp = command;
	command = ft_strjoin(tmp, " | grep 'total leaked bytes'");
	free(tmp);
	system(command);
	ft_putstr(msg);
	ft_putchar('\n');
	free(command);
}
