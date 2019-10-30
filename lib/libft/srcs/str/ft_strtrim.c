/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 11:35:27 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/29 15:27:46 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			stop;
	unsigned int	start;
	char			*str;

	if (!s)
		return (NULL);
	start = 0;
	stop = ft_strlen(s) - 1;
	if (stop > 0)
	{
		while (s[stop] == ' ' || s[stop] == '\n' || s[stop] == '\t')
			stop--;
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
	}
	stop++;
	if (stop == 1)
	{
		if (s[0] == ' ' || s[0] == '\n' || s[0] == '\t')
			stop = 0;
	}
	if (stop < start)
		stop = start;
	str = ft_strsub(s, start, stop - start);
	return (str);
}
