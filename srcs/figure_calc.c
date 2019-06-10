/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 03:22:14 by cfahey            #+#    #+#             */
/*   Updated: 2019/02/18 03:22:16 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		calc_izom_x(int x, int y, int z, int x_zero)
{
	float angle;
	float rad_angle;
	float x_p;

	z = 1;
	angle = 30.0;
	rad_angle = (angle / 180.0) * M_PI;
	x_p = x_zero + x * cos(rad_angle) - y * cos(rad_angle);
	return ((int)x_p * z);
}

int		calc_izom_y(int x, int y, int z, int y_zero)
{
	float angle;
	float rad_angle;
	float y_p;

	angle = 30.0;
	rad_angle = (angle / 180.0) * M_PI;
	y_p = y_zero + x * sin(rad_angle) + y * sin(rad_angle) - z;
	return ((int)y_p);
}

void	assigm_x(t_line *b_l, t_line *o_l, float angle, t_point *center)
{
	float	rad;

	o_l->color0 = b_l->color0;
	o_l->color1 = b_l->color1;
	if (angle > 360)
		angle = angle - 360;
	rad = (angle / 180) * M_PI;
	o_l->xd0 = b_l->xd0;
	o_l->yd0 = (b_l->yd0 - center->y) * cos(rad) -
			(b_l->zd0 - center->z) * sin(rad) + center->y;
	o_l->zd0 = (b_l->yd0 - center->y) * sin(rad) +
			(b_l->zd0 - center->z) * cos(rad) + center->z;
	o_l->xd1 = b_l->xd1;
	o_l->yd1 = (b_l->yd1 - center->y) * cos(rad) -
			(b_l->zd1 - center->z) * sin(rad) + center->y;
	o_l->zd1 = (b_l->yd1 - center->y) * sin(rad) +
			(b_l->zd1 - center->z) * cos(rad) + center->z;
}

void	assigm_y(t_line *b_l, t_line *o_l, float angle, t_point *center)
{
	float	rad;

	o_l->color0 = b_l->color0;
	o_l->color1 = b_l->color1;
	if (angle > 360)
		angle = angle - 360;
	rad = (angle / 180) * M_PI;
	o_l->xd0 = (b_l->xd0 - center->x) * cos(rad) +
		(b_l->zd0 - center->z) * sin(rad) + center->x;
	o_l->yd0 = b_l->yd0;
	o_l->zd0 = -(b_l->xd0 - center->x) * sin(rad) +
			(b_l->zd0 - center->z) * cos(rad) + center->z;
	o_l->xd1 = (b_l->xd1 - center->x) * cos(rad) +
			(b_l->zd1 - center->z) * sin(rad) + center->x;
	o_l->yd1 = b_l->yd1;
	o_l->zd1 = -(b_l->xd1 - center->x) * sin(rad) +
			(b_l->zd1 - center->z) * cos(rad) + center->z;
}

void	assigm_z(t_line *b_l, t_line *o_l, float angle, t_point *center)
{
	float	rad;

	o_l->color0 = b_l->color0;
	o_l->color1 = b_l->color1;
	if (angle > 360)
		angle = angle - 360;
	rad = (angle / 180) * M_PI;
	o_l->xd0 = (b_l->xd0 - center->x) * cos(rad) -
			(b_l->yd0 - center->y) * sin(rad) + center->x;
	o_l->yd0 = (b_l->xd0 - center->x) * sin(rad) +
			(b_l->yd0 - center->y) * cos(rad) + center->y;
	o_l->zd0 = b_l->zd0;
	o_l->xd1 = (b_l->xd1 - center->x) * cos(rad) -
			(b_l->yd1 - center->y) * sin(rad) + center->x;
	o_l->yd1 = (b_l->xd1 - center->x) * sin(rad) +
			(b_l->yd1 - center->y) * cos(rad) + center->y;
	o_l->zd1 = b_l->zd1;
}
