/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:12:29 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/31 21:55:05 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	int		j;
	char	*str;

	len = 0;
	j = 0;
	while (src[len] != '\0')
		len++;
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (j < len)
	{
		str[j] = src[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
