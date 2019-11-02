/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:31:51 by jrouchon          #+#    #+#             */
/*   Updated: 2019/06/21 15:51:12 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char **src, char delim)
{
	size_t	i;
	char	*result;
	char	*tmp;

	i = 0;
	if (*src == NULL)
		return (NULL);
	while ((*src)[i] != delim && (*src)[i] != '\0')
	{
		i++;
	}
	if (i == ft_strlen(*src))
	{
		result = ft_strdup(*src);
		*src[0] = '\0';
	}
	else
	{
		result = ft_strsub(*src, 0, i);
		tmp = *src;
		*src = ft_strsub(tmp, i + 1, ft_strlen(tmp));
		free(tmp);
	}
	return (result);
}
