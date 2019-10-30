/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:39:39 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/29 15:49:36 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!find[0])
		return ((char *)&str[i]);
	while (str[i])
	{
		while (find[j] && (str[i + j] == find[j]))
			j++;
		if (!find[j])
			return ((char *)&str[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
