/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:59:41 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 17:59:43 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	sh_top_color(t_image *image)
{
	int i;
	int j;
	int x;
	int y;
	int color;

	i = 0;
	color = image->top_color;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			x = image->col_map_x + j;
			y = image->col_map_y + i + 360;
			if ((x > 0) && (y > 0) && (x < image->x_size) &&
				(y < image->y_size))
				((int*)(image->data_image))[x + y * (int)image->x_size] = color;
			j++;
		}
		i++;
	}
}

void	sh_base_color(t_image *image)
{
	int i;
	int j;
	int x;
	int y;
	int color;

	i = 0;
	color = image->base_color;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			x = image->col_map_x + j;
			y = image->col_map_y + i + 400;
			if ((x > 0) && (y > 0) && (x < image->x_size) &&
				(y < image->y_size))
				((int*)(image->data_image))[x + y * (int)image->x_size] = color;
			j++;
		}
		i++;
	}
}

void	clear_col_boxes(t_image *image)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			x = image->col_map_x + j;
			y = image->col_map_y + i + 360;
			if ((x > 0) && (y > 0) && (x < image->x_size) &&
				(y < image->y_size))
				((int*)(image->data_image))[x + y * (int)image->x_size] = 0;
			x = image->col_map_x + j;
			y = image->col_map_y + i + 400;
			if ((x > 0) && (y > 0) && (x < image->x_size) &&
				(y < image->y_size))
				((int*)(image->data_image))[x + y * (int)image->x_size] = 0;
			j++;
		}
		i++;
	}
}

void	line_grad(t_image *image, int color)
{
	int		i;
	int		j;
	int		x;
	int		y;
	double	step;

	step = color / 255;
	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 255)
		{
			x = image->col_map_x + j;
			y = image->col_map_y + i + 320;
			if ((x > 0) && (y > 0) && (x < image->x_size) &&
				(y < image->y_size))
			{
				y = y * (int)image->x_size;
				((int*)(image->data_image))[x + y] = (int)(j * step);
			}
			j++;
		}
		i++;
	}
}

void	clear_line_grad(t_image *image)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 255)
		{
			x = image->col_map_x + j;
			y = image->col_map_y + i + 320;
			if ((x > 0) && (y > 0) && (x < image->x_size) &&
				(y < image->y_size))
				((int*)(image->data_image))[x + y * (int)image->x_size] = 0;
			j++;
		}
		i++;
	}
}
