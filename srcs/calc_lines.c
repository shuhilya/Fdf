/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 03:28:13 by cfahey            #+#    #+#             */
/*   Updated: 2019/02/18 03:28:14 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	func0(t_fileview *f, t_point *p0, t_point *p1, t_line **lines)
{
	if (f->j == f->x_size - 2)
	{
		p0->x = (f->j + 1) * f->step;
		p0->y = f->i * f->step;
		p0->z = f->data[f->i][f->j + 1] * f->height;
		p0->color = f->color[f->i][f->j + 1];
		p1->x = (f->j + 1) * f->step;
		p1->y = (f->i + 1) * f->step;
		p1->z = f->data[f->i + 1][f->j + 1] * f->height;
		p1->color = f->color[f->i + 1][f->j + 1];
		(*lines)->next = cr_line_st(p0, p1);
		(*lines) = (*lines)->next;
	}
}

void	func1(t_fileview *f, t_line **lines)
{
	f->p1->x = f->j * f->step;
	f->p1->y = (f->i + 1) * f->step;
	f->p1->z = f->data[f->i + 1][f->j] * f->height;
	f->p1->color = f->color[f->i + 1][f->j];
	(*lines)->next = cr_line_st(f->p0, f->p1);
	(*lines) = (*lines)->next;
	if (f->j == f->x_size - 2)
	{
		func0(f, f->p0, f->p1, &*lines);
	}
	if (f->i == f->y_size - 2)
	{
		f->p0->x = f->j * f->step;
		f->p0->y = (f->i + 1) * f->step;
		f->p0->z = f->data[f->i + 1][f->j] * f->height;
		f->p0->color = f->color[f->i + 1][f->j];
		f->p1->x = (f->j + 1) * f->step;
		f->p1->y = (f->i + 1) * f->step;
		f->p1->z = f->data[f->i + 1][f->j + 1] * f->height;
		f->p1->color = f->color[f->i + 1][f->j + 1];
		(*lines)->next = cr_line_st(f->p0, f->p1);
		(*lines) = (*lines)->next;
	}
}

void	func2(t_fileview *f)
{
	f->p0->x = f->j * f->step;
	f->p0->y = f->i * f->step;
	f->p0->z = f->data[f->i][f->j] * f->height;
	f->p0->color = f->color[f->i][f->j];
	f->p1->x = (f->j + 1) * f->step;
	f->p1->y = f->i * f->step;
	f->p1->z = f->data[f->i][f->j + 1] * f->height;
	f->p1->color = f->color[f->i][f->j + 1];
}

void	func3(t_fileview *f, t_line **lines, t_line **start)
{
	if ((f->i == 0) && (f->j == 0))
	{
		*lines = cr_line_st(f->p0, f->p1);
		*start = *lines;
	}
	else
	{
		(*lines)->next = cr_line_st(f->p0, f->p1);
		*lines = (*lines)->next;
	}
}

t_line	*calc_lines(t_fileview *f, double d_step, double d_height)
{
	t_line	*lines;
	t_line	*start;

	f->step = (int)d_step;
	f->height = d_step / d_height * 2;
	f->p0 = (t_point *)malloc(sizeof(t_point));
	f->p1 = (t_point *)malloc(sizeof(t_point));
	f->i = 0;
	start = NULL;
	lines = NULL;
	while (f->i < f->y_size - 1)
	{
		f->j = 0;
		while (f->j < f->x_size - 1)
		{
			func2(f);
			func3(f, &lines, &start);
			func1(f, &lines);
			f->j++;
		}
		f->i++;
	}
	return (start);
}
