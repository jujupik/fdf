/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:09:57 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/28 22:34:23 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t len)
{
	char *str;

	str = (char*)ft_memalloc(sizeof(char) * (len + 1));
	if (str == NULL)
		error_exit(112, "Can't malloc a char *");
	return (str);
}
