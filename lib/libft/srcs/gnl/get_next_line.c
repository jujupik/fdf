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

t_list	*find_fd(t_list *list, int fd)
{
	t_list	*to_del;
	t_list	*buf_list;

	buf_list = list;
	if (!buf_list)
		return (NULL);
	while (buf_list && ((int)buf_list->content_size != fd))
	{
		if (buf_list->next && (ft_strlen(buf_list->next->content) == 0))
		{
			to_del = buf_list->next;
			buf_list->next = buf_list->next->next;
			free(to_del->content);
			free(to_del);
		}
		buf_list = buf_list->next;
	}
	return (buf_list);
}

char	*buf_manager(int fd, t_list **lst)
{
	static t_list	*buf_list = 0;
	t_list			*cur_buf;

	cur_buf = find_fd(buf_list, fd);
	if (fd == -1 && buf_list && (ft_strlen(buf_list->content) == 0))
	{
		free(buf_list->content);
		free(buf_list);
		buf_list = 0;
	}
	if (fd == -1)
		return (NULL);
	if (!cur_buf)
	{
		cur_buf = ft_lstnew("", fd);
		if (buf_list)
			ft_lstadd(&buf_list, cur_buf);
		else
			buf_list = cur_buf;
	}
	*lst = cur_buf;
	if (cur_buf)
		return (cur_buf->content);
	return (NULL);
}

char	*readfd(int fd, char **str)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	if (ft_strchr(*str, '\n'))
		return (*str);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (buff[0] == '\0')
			return (ft_strjoin(tmp, buff));
		buff[ret] = '\0';
		tmp = *str;
		if (!(*str = ft_strjoin(tmp, buff)))
			return (0);
		free(tmp);
		if (ft_strchr(*str, '\n'))
			return (*str);
	}
	return (*str);
}

char	*free_sub(char **str, int *i)
{
	char	*tmp;

	tmp = *str;
	*str = ft_strsub(tmp, *i + 1, ft_strlen(*str));
	free(tmp);
	return (*str);
}

int		get_next_line(const int fd, char **line)
{
	t_list	*lst;
	char	*str;
	int		i;

	if (!line || fd == -1 || (read(fd, 0, 0) == -1))
		return (-1);
	str = buf_manager(fd, &lst);
	if (!(str = readfd(fd, &str)))
		return (-1);
	i = 0;
	if (str[i])
	{
		while (str[i] && str[i] != '\n')
			i++;
		(*line) = ft_strsub(str, 0, i);
		if (str[i] == '\n')
			str = free_sub(&str, &i);
		else
			str[0] = '\0';
		lst->content = str;
		buf_manager(-1, &lst);
		return (1);
	}
	buf_manager(-1, &lst);
	return (0);
}
