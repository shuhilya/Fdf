/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:01:10 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 18:01:12 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_sets(t_image *image, int keycode, int step, t_angles *angles)
{
	if (keycode == 69)
		image->mult = image->mult * 1.1;
	if (keycode == 78)
		image->mult = image->mult * 0.9;
	if (keycode == 0)
		image->x_shift = image->x_shift - step;
	if (keycode == 2)
		image->x_shift = image->x_shift + step;
	if (keycode == 13)
		image->y_shift = image->y_shift - step;
	if (keycode == 1)
		image->y_shift = image->y_shift + step;
	if (keycode == 7)
		angles->ang_x = angles->ang_x + 10 * image->angle_flag;
	if (keycode == 16)
		angles->ang_y = angles->ang_y + 10 * image->angle_flag;
	if (keycode == 6)
		angles->ang_z = angles->ang_z + 10 * image->angle_flag;
	if (keycode == 256)
		image->angle_flag = image->angle_flag * -1;
	if (keycode == 32)
		set_user_color(image->base_lines, image->winsets->fileview, image);
	if (keycode == 11)
		set_base_color(image->base_lines, image->winsets->fileview, image);
}

void	incr_height(t_image *image)
{
	if (image->height < -0.01)
	{
		image->height = image->height * 0.9;
		image->center->z = image->center->z * 0.9;
	}
	else
	{
		if (image->minus_to_plus)
		{
			image->height = 0.01;
			image->plus_to_minus = 1;
			image->minus_to_plus = 0;
		}
		image->height = image->height * 1.1;
		image->center->z = image->center->z * 1.1;
	}
}

void	decr_height(t_image *image)
{
	if (image->height > 0.01)
	{
		image->height = image->height * 0.9;
		image->center->z = image->center->z * 0.9;
	}
	else
	{
		if (image->plus_to_minus)
		{
			image->height = -0.01;
			image->plus_to_minus = 0;
			image->minus_to_plus = 1;
		}
		image->height = image->height * 1.1;
		image->center->z = image->center->z * 1.1;
	}
}
