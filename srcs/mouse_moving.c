/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_moving.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:02:57 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 18:02:59 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	non_col_mod_moving(t_image *image, int x, int y)
{
	int		dx;
	int		dy;

	dx = image->x_pos - x;
	dy = image->y_pos - y;
	if (image->flag == 1)
	{
		image->color = 0;
		set_all(image, 1);
		image->x_shift = image->x_shift - dx;
		image->y_shift = image->y_shift - dy;
		image->color = 1;
		set_all(image, 0);
		image->x_pos = x;
		image->y_pos = y;
	}
}

void	col_mode_moving(t_image *image, int x, int y)
{
	int clr;

	if (image->flag == 1)
	{
		image->color = 0;
		set_all(image, 1);
		if ((x > image->col_map_x) && (x < image->col_map_x + 255))
			if ((y > image->col_map_y + 320) && (y < image->col_map_y + 340))
			{
				clr = ((int *)(image->data_image))[x + y * (int)image->x_size];
				image->ground_col = clr;
				color_map(image->ground_col, image, 0, 0);
			}
		image->color = 1;
		set_all(image, 0);
	}
}

int		mouse_move(int x, int y, void *param)
{
	t_image *image;

	image = (t_image *)param;
	if (image->glob_mode || image->help_mode)
		non_col_mod_moving(image, x, y);
	if (image->col_mode)
		col_mode_moving(image, x, y);
	return (0);
}
