/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_sed_funks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:02:33 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 18:02:34 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_mode_set(t_image *image)
{
	image->glob_mode = 0;
	image->help_mode = 0;
	image->col_mode = 1;
	color_map(image->ground_col, image, 0, 0);
	sh_top_color(image);
	sh_base_color(image);
	line_grad(image, image->main_color);
	image->res_interface = 1;
}

void	glob_mode_set(t_image *image)
{
	if (image->col_mode)
	{
		clear_col_map(image);
		clear_col_boxes(image);
		clear_line_grad(image);
		image->col_mode = 0;
	}
	image->help_mode = 0;
	image->glob_mode = 1;
	image->res_interface = 1;
}

void	help_mode_set(t_image *image)
{
	if (image->col_mode)
	{
		clear_col_map(image);
		clear_col_boxes(image);
		clear_line_grad(image);
		image->col_mode = 0;
	}
	image->help_mode = 1;
	image->glob_mode = 0;
	image->res_interface = 1;
}
