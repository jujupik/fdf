/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:27:19 by jrouchon          #+#    #+#             */
/*   Updated: 2019/02/01 17:33:47 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*flst;

	if (!lst)
		return (NULL);
	flst = f(lst);
	new = flst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(flst->next = f(lst)))
		{
			return (NULL);
		}
		flst = flst->next;
	}
	return (new);
}
