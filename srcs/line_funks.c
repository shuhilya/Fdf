/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_funks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:01:41 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 18:01:43 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_line(t_line *lines, int x_zero, int y_zero, t_image *image)
{
	t_draw	*draw;
	double	shft;

	draw = (t_draw *)malloc(sizeof(t_draw));
	shft = image->x_shift;
	draw->x0 = calc_izom_x(lines->xd0, lines->yd0, lines->zd0, x_zero) + shft;
	draw->x1 = calc_izom_x(lines->xd1, lines->yd1, lines->zd1, x_zero) + shft;
	shft = image->y_shift;
	draw->y0 = calc_izom_y(lines->xd0, lines->yd0, lines->zd0, y_zero) + shft;
	draw->y1 = calc_izom_y(lines->xd1, lines->yd1, lines->zd1, y_zero) + shft;
	if (image->color)
		draw_line(image, draw, lines->color0, lines->color1);
	else
		draw_line(image, draw, 0, 0);
	free(draw);
}

void	line_copy(t_line *src, t_line *dest)
{
	dest->xd0 = src->xd0;
	dest->xd1 = src->xd1;
	dest->yd0 = src->yd0;
	dest->yd1 = src->yd1;
	dest->zd0 = src->zd0;
	dest->zd1 = src->zd1;
	dest->color0 = src->color0;
	dest->color1 = src->color1;
}

t_line	*cr_line_st(t_point *p0, t_point *p1)
{
	t_line	*line_struct;

	line_struct = (t_line*)malloc(sizeof(t_line));
	line_struct->xd0 = p0->x;
	line_struct->xd1 = p1->x;
	line_struct->yd0 = p0->y;
	line_struct->yd1 = p1->y;
	line_struct->zd0 = p0->z;
	line_struct->zd1 = p1->z;
	line_struct->color0 = p0->color;
	line_struct->color1 = p1->color;
	line_struct->next = NULL;
	return (line_struct);
}
