/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:59:56 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 17:59:58 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	choose_col_base(t_image *image, int keycode)
{
	if (keycode == 15)
	{
		image->main_color = 0xFF0000;
		image->ground_col = 0xFF0000;
		color_map(image->ground_col, image, 0, 0);
		line_grad(image, image->main_color);
	}
	if (keycode == 5)
	{
		image->main_color = 0x00FF00;
		image->ground_col = 0x00FF00;
		color_map(image->ground_col, image, 0, 0);
		line_grad(image, image->main_color);
	}
	if (keycode == 11)
	{
		image->main_color = 0x0000FF;
		image->ground_col = 0x0000FF;
		color_map(image->ground_col, image, 0, 0);
		line_grad(image, image->main_color);
	}
}

void	set_map_color(int stat_color, int *shift1, int *shift2)
{
	if (stat_color & 0xFF0000)
	{
		*shift1 = 0;
		*shift2 = 8;
	}
	else if (stat_color & 0x00FF00)
	{
		*shift1 = 0;
		*shift2 = 16;
	}
	else
	{
		*shift1 = 8;
		*shift2 = 16;
	}
}

void	color_map(int stat_color, t_image *image, int x, int y)
{
	int	i;
	int	j;
	int	color;
	int	shift1;
	int	shift2;

	set_map_color(stat_color, &shift1, &shift2);
	i = -1;
	while (++i <= 255)
	{
		j = 0;
		while (j <= 255)
		{
			color = color | (i << shift1);
			color = color | (j << shift2);
			color = color | stat_color;
			x = image->col_map_x + j;
			y = image->col_map_y + i;
			if ((x > 0) && (y > 0) && (x < image->x_size) &&
				(y < image->y_size))
				((int*)(image->data_image))[x + y * (int)image->x_size] = color;
			color = 0;
			j++;
		}
	}
}

void	clear_col_map(t_image *image)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	while (i <= 255)
	{
		j = 0;
		while (j <= 255)
		{
			x = image->col_map_x + j;
			y = image->col_map_y + i;
			if ((x > 0) && (y > 0) && (x < image->x_size) &&
				(y < image->y_size))
				((int*)(image->data_image))[x + y * (int)image->x_size] = 0;
			j++;
		}
		i++;
	}
}

int		rgb(int color0, int color1, double max_height, double current_height)
{
	double	dh;
	double	dr;
	double	dg;
	double	db;
	int		color;

	color = 0;
	dh = current_height / max_height;
	dr = (((color1 & 0xFF0000) >> 16) - ((color0 & 0xFF0000) >> 16));
	dg = (((color1 & 0xFF00) >> 8) - ((color0 & 0xFF00) >> 8));
	db = ((color1 & 0xFF) - (color0 & 0xFF));
	dr = ((color0 & 0xFF0000) >> 16) + dr * dh;
	dg = ((color0 & 0xFF00) >> 8) + dg * dh;
	db = ((color0 & 0xFF)) + db * dh;
	color |= (((int)dr) << 16);
	color |= (((int)dg) << 8);
	color |= (((int)db));
	return (color);
}
