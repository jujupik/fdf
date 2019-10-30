/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:17:22 by jrouchon          #+#    #+#             */
/*   Updated: 2019/01/28 19:18:05 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_len(int n)
{
	unsigned int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	l;
	unsigned int	i;

	i = 0;
	l = find_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * l + 1);
	if (!str)
		return (NULL);
	str[l] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		i++;
	}
	if (n < 0)
		n = -n;
	while (i < l--)
	{
		str[l] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
