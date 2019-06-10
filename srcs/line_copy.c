/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 03:22:28 by cfahey            #+#    #+#             */
/*   Updated: 2019/02/18 03:22:30 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	ft_put_pixel(t_draw *drw, t_image *image)
{
	if (drw->dy < drw->dx)
	{
		if ((drw->x > image->bor_x_min) && (ipart(drw->tmp) > image->bor_y_min)
			&& (drw->x < image->bor_x_max) && (ipart(drw->tmp) <
			image->bor_y_max))
			((int *)(image->data_image))[(int)drw->x + ((int)drw->tmp) *
			(int)image->x_size] = drw->set_color;
	}
	else
	{
		if ((ipart(drw->tmp) > image->bor_x_min) && (drw->y > image->bor_y_min)
			&& (ipart(drw->tmp) < image->bor_x_max) && (drw->y <
			image->bor_y_max))
			((int *)(image->data_image))[(int)drw->tmp +
			((int)drw->y) * (int)image->x_size] =
					drw->set_color;
	}
}

void	plot(t_image *image, double c, t_draw *draw)
{
	int		color;
	float	fcolor;

	fcolor = (float)(draw->o_c & 0x0000FF) * (float)c;
	color = ((int)fcolor) & 0x0000FF;
	draw->set_color = (color);
	fcolor = (float)(draw->o_c & 0x00FF00) * (float)c;
	color = ((int)fcolor) & 0x00FF00;
	draw->set_color = draw->set_color | color;
	fcolor = (float)(draw->o_c & 0xFF0000) * (float)c;
	color = ((int)fcolor) & 0xFF0000;
	draw->set_color = draw->set_color | color;
	change_pixel(draw, image);
	ft_put_pixel(draw, image);
}

void	draw_x_line(t_image *image, t_draw *draw, int color0, int color1)
{
	draw->sign = 1;
	if (draw->x1 < draw->x0)
	{
		swap_double(&draw->x0, &draw->x1);
		swap_double(&draw->y0, &draw->y1);
		swap_int(&color0, &color1);
	}
	draw->x = ft_round(draw->x0);
	draw->in = draw->y0 + draw->dy / draw->dx * (ft_round(draw->x0) - draw->x0);
	if (draw->y1 < draw->y0)
		draw->sign = -1;
	draw->c_s_r = COLOR_STEP_R(color1, color0, draw->x1, draw->x);
	draw->c_s_g = COLOR_STEP_G(color1, color0, draw->x1, draw->x);
	draw->c_s_b = COLOR_STEP_B(color1, color0, draw->x1, draw->x);
	while (draw->x < ft_round(draw->x1) + 1)
	{
		draw->o_c_r = ONE_R(color0, draw->x, draw->x0, draw->c_s_r);
		draw->o_c_g = ONE_G(color0, draw->x, draw->x0, draw->c_s_g);
		draw->o_c_b = ONE_B(color0, draw->x, draw->x0, draw->c_s_b);
		draw->o_c = draw->o_c_r | draw->o_c_g | draw->o_c_b;
		plot(image, 1 - fpart(draw->in), draw);
		plot(image, fpart(draw->in), draw);
		draw->in = draw->in + draw->sign * draw->dy / draw->dx;
		draw->x++;
	}
}

void	draw_y_line(t_image *image, t_draw *draw, int color0, int color1)
{
	draw->sign = 1;
	if (draw->y1 < draw->y0)
	{
		swap_double(&draw->x0, &draw->x1);
		swap_double(&draw->y0, &draw->y1);
		swap_int(&color0, &color1);
	}
	draw->y = ft_round(draw->y0);
	draw->in = draw->x0 + draw->dx / draw->dy * (ft_round(draw->y0) - draw->y0);
	if (draw->x1 < draw->x0)
		draw->sign = -1;
	draw->c_s_r = COLOR_STEP_R(color1, color0, draw->y1, draw->y);
	draw->c_s_g = COLOR_STEP_G(color1, color0, draw->y1, draw->y);
	draw->c_s_b = COLOR_STEP_B(color1, color0, draw->y1, draw->y);
	while (draw->y < ft_round(draw->y1) + 1)
	{
		draw->o_c_r = ONE_R(color0, draw->y, draw->y0, draw->c_s_r);
		draw->o_c_g = ONE_G(color0, draw->y, draw->y0, draw->c_s_g);
		draw->o_c_b = ONE_B(color0, draw->y, draw->y0, draw->c_s_b);
		draw->o_c = draw->o_c_r | draw->o_c_g | draw->o_c_b;
		plot(image, 1 - fpart(draw->in), draw);
		plot(image, fpart(draw->in), draw);
		draw->in = draw->in + draw->sign * draw->dx / draw->dy;
		draw->y++;
	}
}

void	draw_line(t_image *image, t_draw *drw, int color0, int color1)
{
	drw->dx = (drw->x1 > drw->x0) ? (drw->x1 - drw->x0) : (drw->x0 - drw->x1);
	drw->dy = (drw->y1 > drw->y0) ? (drw->y1 - drw->y0) : (drw->y0 - drw->y1);
	if (drw->dy < drw->dx)
	{
		draw_x_line(image, drw, color0, color1);
	}
	else
	{
		draw_y_line(image, drw, color0, color1);
	}
}
