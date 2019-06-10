/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_add_funk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:04:19 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 18:04:20 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	min_step(t_image *image, t_fileview *fileview)
{
	double	x_step;
	double	y_step;
	int		x_size;
	int		y_size;

	x_size = image->bor_x_max - image->bor_x_min;
	y_size = image->bor_y_max - image->bor_y_min;
	x_step = cos(M_PI * 30 / 180);
	x_step = x_size / (x_step * (fileview->x_size + fileview->y_size));
	y_step = sin(M_PI * 30 / 180);
	y_step = y_size / (y_step * (fileview->x_size + fileview->y_size));
	if (x_step < y_step)
		return (x_step);
	return (y_step);
}

double	max_height(t_fileview *fileview)
{
	int		i;
	int		j;
	double	res;
	double	count;

	res = 0;
	i = 0;
	while (i < fileview->y_size)
	{
		j = 0;
		while (j < fileview->x_size)
		{
			count = (double)(fileview->data[i][j]);
			if (res < count)
				res = count;
			j++;
		}
		i++;
	}
	return (res);
}

void	set_glob_pos(t_image *image, t_fileview *fileview, t_winsets *winsets)
{
	double		max_z;
	double		step;

	image->bor_x_min = 0;
	image->bor_x_max = image->x_size;
	image->bor_y_min = 0;
	image->bor_y_max = image->y_size;
	step = min_step(image, fileview);
	image->cur_max_height = (int)(2 * step);
	max_z = max_height(fileview);
	image->lines_step = step;
	second_sets(image, winsets, step, max_z);
	image->center->x = fileview->x_size * step / 2;
	image->center->y = fileview->y_size * step / 2;
	image->center->z = (int)(max_z / 2 * (step / max_z * 2));
}
