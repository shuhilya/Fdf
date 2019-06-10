/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:01:22 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 18:01:24 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	figure_moves(t_image *image, int keycode, int step, t_angles *angles)
{
	key_sets(image, keycode, step, angles);
	if (keycode == 4)
		incr_height(image);
	if (keycode == 37)
		decr_height(image);
}

void	color_sets(t_image *image, int keycode)
{
	if (keycode == 4)
	{
		image->col_top_flag = 1;
		image->col_bot_flag = 0;
	}
	if (keycode == 37)
	{
		image->col_top_flag = 0;
		image->col_bot_flag = 1;
	}
	if (keycode == 1)
		set_user_color(image->base_lines, image->winsets->fileview, image);
	choose_col_base(image, keycode);
}

void	mode_sets(t_image *image, int keycode)
{
	if (keycode == 8)
		color_mode_set(image);
	if (keycode == 14)
		glob_mode_set(image);
	if (keycode == 34)
		help_mode_set(image);
}

int		key_press(int keycode, void *param)
{
	t_image		*image;
	double		step;
	t_angles	*angles;

	step = 40;
	image = (t_image *)param;
	angles = image->angles;
	image->color = 0;
	set_all(image, 1);
	if (image->glob_mode || image->help_mode)
		figure_moves(image, keycode, step, angles);
	if (image->col_mode)
		color_sets(image, keycode);
	if (keycode == 53)
		ft_close((void *)0);
	mode_sets(image, keycode);
	image->color = 1;
	set_all(image, 0);
	return (keycode);
}
