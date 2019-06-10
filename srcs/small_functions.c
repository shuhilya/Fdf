/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 03:22:55 by cfahey            #+#    #+#             */
/*   Updated: 2019/02/18 03:22:55 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_y(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) == 1)
		i++;
	return (i);
}

int		print_hex(int n)
{
	if (n >= 16)
		print_hex(n / 16);
	n = n % 16;
	n += n < 10 ? '0' : 'a' - 10;
	return (n);
}

void	change_pixel(t_draw *draw, t_image *image)
{
	draw->i++;
	if (draw->i % 2 == 0)
	{
		draw->tmp = ipart(draw->in + 1);
		ft_put_pixel(draw, image);
	}
	else
	{
		draw->tmp = ipart(draw->in);
		ft_put_pixel(draw, image);
	}
}

void	zoom(t_line *line, double d)
{
	line->xd0 *= d;
	line->yd0 *= d;
	line->zd0 *= d;
	line->xd1 *= d;
	line->yd1 *= d;
	line->zd1 *= d;
}

void	user_instr(int flag, char *s)
{
	if (flag == 1)
		ft_putstr("Give to the function only one argument!!\n");
	if (flag == 2)
	{
		ft_putstr("File ");
		ft_putstr(s);
		ft_putstr(" does not exist!!\n");
	}
	if (flag == 3)
	{
		ft_putstr("It isn't a file. ");
		ft_putstr("It is a folder!!\n");
	}
	if (flag == 4)
	{
		ft_putstr("It is not valid file.");
	}
	exit(0);
}
