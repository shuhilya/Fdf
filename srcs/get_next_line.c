/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <cfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 06:20:24 by cfahey            #+#    #+#             */
/*   Updated: 2018/12/21 10:17:36 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*get_file(t_list **line, int fd)
{
	t_list	*that;

	that = *line;
	while (that)
	{
		if ((int)that->content_size == fd)
			return (that);
		that = that->next;
	}
	ft_lstadd(line, ft_lstnew("", 1));
	(*line)->content_size = fd;
	return (*line);
}

static int		check(const int fd, char **line, char **content, char *buf)
{
	char			*tmp;
	size_t			len;
	ssize_t			ret;
	char			*ln;

	while (!(ln = ft_strchr(*content, '\n')) &&
			(ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = *content;
		*content = ft_joincatfree(*content, buf, 1);
	}
	if (!ret && !ft_strlen(*content))
		return (0);
	len = ft_strlen(*content);
	*line = ft_strnew(ln ? ln - *content : len);
	ft_strncpy(*line, *content, ln ? ln - *content : len);
	tmp = *content;
	*content = ft_strdup(ln ? ln + 1 : "");
	free(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*current_file;
	char			*buf;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE == 0 ||
			!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	current_file = get_file(&file, fd);
	ret = check(fd, line, (char **)&current_file->content, buf);
	free(buf);
	return (ret);
}
