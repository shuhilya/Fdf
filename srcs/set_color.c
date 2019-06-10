/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 03:22:47 by cfahey            #+#    #+#             */
/*   Updated: 2019/02/18 03:22:48 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_base_color(t_line *lines, t_fileview *fileview, t_image *image)
{
	int	i;
	int j;
	int step;

	step = image->lines_step;
	while (lines != NULL)
	{
		j = lines->xd0 / step;
		i = lines->yd0 / step;
		lines->color0 = fileview->color[i][j];
		j = lines->xd1 / step;
		i = lines->yd1 / step;
		lines->color1 = fileview->color[i][j];
		lines = lines->next;
	}
}

void	set_user_color(t_line *lines, t_fileview *fileview, t_image *image)
{
	(void)fileview;
	while (lines != NULL)
	{
		lines->color0 = rgb(image->base_color, image->top_color,
				image->cur_max_height, lines->zd0);
		lines->color1 = rgb(image->base_color, image->top_color,
				image->cur_max_height, lines->zd1);
		lines = lines->next;
	}
}

char	*color(char *s)
{
	int		i;
	char	*tmp;

	i = 3;
	tmp = ft_strchr(s, ',');
	if (tmp != NULL)
		v(tmp, &i);
	else
	{
		i = 0;
		while (s[i])
		{
			if (!(s[i] >= '0' && s[i++] <= '9'))
				user_instr(4, "");
		}
		tmp = "FFFFFF";
		return (tmp);
	}
	return (tmp + 3);
}

int		get_color(char *str)
{
	char	*s;
	int		n1;
	int		whole_n;
	int		i;

	whole_n = 0;
	if (*str)
	{
		s = color(str);
		i = 0;
		while (i < 6)
		{
			if ((s[i] >= 'A') && (s[i] <= 'F'))
				n1 = 10 + s[i] - 'A';
			else if ((s[i] >= 'a') && (s[i] <= 'f'))
				n1 = 10 + s[i] - 'a';
			else
				n1 = s[i] - '0';
			n1 = n1 << 4 * (5 - i);
			whole_n = whole_n | n1;
			i++;
		}
	}
	return (whole_n);
}

int		*get_line_color(char **color, int max_x)
{
	int		a;
	int		*col;

	a = 0;
	if ((col = (int *)malloc(sizeof(int) * max_x)) == 0)
		return (NULL);
	while (color[a] && a < max_x)
	{
		col[a] = get_color(color[a]);
		a++;
	}
	return (col);
}
