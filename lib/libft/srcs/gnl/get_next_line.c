/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:31:51 by jrouchon          #+#    #+#             */
/*   Updated: 2019/06/21 15:51:12 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				get_next_line(const int fd, char **line)
{
	int			result;
	char		buff[BUFF_SIZE + 1];
	static char	*saved[590432];

	result = 1;
	while (ft_strcchr(saved[fd], '\n') <= 0)
	{
		result = read(fd, buff, BUFF_SIZE);
		if (result == 0)
			break ;
		buff[result] = '\0';
		saved[fd] = ft_strjoin(saved[fd], buff);
	}
	*line = ft_strcut(&(saved[fd]), '\n');
	return (ft_strlen(*line) + ft_strlen(saved[fd]) + result);
}
