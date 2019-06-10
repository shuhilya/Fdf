/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 03:21:19 by cfahey            #+#    #+#             */
/*   Updated: 2019/02/18 03:21:24 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		free_split(char **split, int ret)
{
	int	i;

	i = 0;
	while (split[i] && i < ret)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int			get_int(const char *str)
{
	int nbr;

	nbr = 0;
	if (*str && *str == '0')
		nbr = 0;
	else if (*str && *str > '0' && *str <= '9')
		nbr = ft_atoi(&(*str));
	return (nbr);
}

int			*get_line(char **line, int max_x)
{
	int		a;
	int		*tab;

	a = 0;
	if ((tab = (int *)malloc(sizeof(int) * max_x)) == 0)
		return (NULL);
	while (line[a] && a < max_x)
	{
		tab[a] = get_int(line[a]);
		a++;
	}
	return (tab);
}

void		ft_read(t_reader *stream, t_fileview *file, int fd, int tmp)
{
	int	ft;

	while ((ft = get_next_line(fd, &stream->line)) == 1 &&
	(stream->a < file->y_size))
	{
		stream->split = ft_strsplit(stream->line, ' ');
		while (stream->split[stream->ret])
		{
			if (tmp != 0)
				user_instr(4, "");
			stream->ret++;
		}
		if (!stream->split[stream->ret - 1])
			user_instr(4, "");
		if (tmp != 0 && stream->ret != tmp)
			user_instr(4, "");
		tmp = stream->ret;
		stream->tab[stream->a++] = get_line(stream->split, stream->ret);
		stream->col[stream->b++] = get_line_color(stream->split, stream->ret);
		free_split(stream->split, stream->ret);
		ft_memdel((void **)&stream->line);
	}
	if (ft < 0)
		user_instr(3, "");
}

t_fileview	*reader(int fd, int y, t_fileview *file)
{
	t_reader	*stream;

	stream = (t_reader *)malloc(sizeof(t_reader));
	stream->a = 0;
	stream->b = 0;
	stream->ret = 0;
	file->y_size = y;
	if ((stream->col = (int **)malloc(sizeof(int *) * file->y_size)) == 0)
		return (NULL);
	if ((stream->tab = (int **)malloc(sizeof(int *) * file->y_size)) == 0)
		return (NULL);
	ft_read(stream, file, fd, 0);
	file->data = stream->tab;
	file->color = stream->col;
	file->x_size = stream->ret;
	return (file);
}
