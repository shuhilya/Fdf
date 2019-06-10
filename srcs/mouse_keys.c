/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:02:47 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 18:02:49 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	non_col_mod_reactions(t_image *image, int button, int x, int y)
{
	if (button == 1)
	{
		image->flag = 1;
		image->x_pos = x;
		image->y_pos = y;
	}
	if (image->glob_mode || image->help_mode)
	{
		if (button == 4)
		{
			image->color = 0;
			set_all(image, 1);
			image->mult *= 1.1;
			image->color = 1;
			set_all(image, 0);
		}
		if (button == 5)
		{
			image->color = 0;
			set_all(image, 1);
			image->mult *= 0.9;
			image->color = 1;
			set_all(image, 0);
		}
	}
}

void	click_on_col_box(t_image *image, int x, int y)
{
	int color;

	if (image->col_top_flag)
	{
		color = ((int *)(image->data_image))[x + y * (int)image->x_size];
		image->top_color = color;
		sh_top_color(image);
	}
	if (image->col_bot_flag)
	{
		color = ((int *)(image->data_image))[x + y * (int)image->x_size];
		image->base_color = color;
		sh_base_color(image);
	}
}

void	click_on_gradient(t_image *image, int x, int y)
{
	int color;

	color = ((int *)(image->data_image))[x + y * (int)image->x_size];
	image->ground_col = color;
	color_map(image->ground_col, image, 0, 0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_image *image;

	image = (t_image *)param;
	non_col_mod_reactions(image, button, x, y);
	if (image->col_mode)
	{
		image->color = 0;
		set_all(image, 1);
		if ((x > image->col_map_x) && (x < image->col_map_x + 255))
			if ((y > image->col_map_y) && (y < image->col_map_y + 255))
				click_on_col_box(image, x, y);
		if ((x > image->col_map_x) && (x < image->col_map_x + 255))
			if ((y > image->col_map_y + 320) && (y < image->col_map_y + 340))
				click_on_gradient(image, x, y);
		image->color = 1;
		set_all(image, 0);
	}
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_image *image;

	(void)button;
	(void)x;
	(void)y;
	image = (t_image *)param;
	image->flag = 0;
	return (0);
}
