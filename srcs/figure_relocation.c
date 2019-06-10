/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_relocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:00:29 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 18:00:31 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	b_mult(t_image *image, t_borders *brs, int *old_cen_x, int *old_cen_y)
{
	t_fileview	*fview;
	int			step;
	double		part;
	int			xy;
	int			z;

	fview = image->winsets->fileview;
	step = image->lines_step;
	part = 2 * step / max_height(fview);
	z = (int)(fview->data[0][0] * part);
	brs->y_lb = calc_izom_y(0, 0, z, image->y_zero);
	xy = step * (fview->x_size - 1);
	z = (int)(fview->data[0][fview->x_size - 1] * part);
	brs->x_rb = calc_izom_x(xy, 0, z, image->x_zero);
	xy = step * (fview->x_size - 1);
	z = (int)(fview->data[fview->y_size - 1][fview->x_size - 1] * part);
	brs->y_rt = calc_izom_y(xy, step * (fview->y_size - 1), z, image->x_zero);
	xy = step * (fview->y_size - 1);
	z = (int)(fview->data[fview->y_size - 1][0] * part);
	brs->x_lt = calc_izom_x(0, xy, z, image->x_zero);
	*old_cen_x = (brs->x_rb - brs->x_lt) / 2 + brs->x_lt;
	*old_cen_y = (brs->y_rt - brs->y_lb) / 2 + brs->y_lb;
}

void	after_mult(double part, t_image *im, int *old_cen_x, int *old_cen_y)
{
	t_borders	*borders;
	t_fileview	*fw;
	int			x;
	int			y;
	int			z;

	fw = im->winsets->fileview;
	borders = (t_borders*)malloc(sizeof(t_borders));
	z = (int)(fw->data[0][0] * part * im->mult);
	borders->y_lb = calc_izom_y(0, 0, z, im->y_zero);
	z = (int)((fw->data[0][fw->x_size - 1] * part) * im->mult);
	x = (int)(im->lines_step * (fw->x_size - 1) * im->mult);
	borders->x_rb = calc_izom_x(x, 0, z, im->x_zero);
	x = (int)(im->lines_step * (fw->x_size - 1) * im->mult);
	y = (int)(im->lines_step * (fw->y_size - 1) * im->mult);
	z = (int)((fw->data[fw->y_size - 1][fw->x_size - 1] * part) * im->mult);
	borders->y_rt = calc_izom_y(x, y, z, im->x_zero);
	y = (int)(im->lines_step * (fw->y_size - 1) * im->mult);
	z = (int)((fw->data[fw->y_size - 1][0] * part) * im->mult);
	borders->x_lt = calc_izom_x(0, y, z, im->x_zero);
	*old_cen_x = (borders->x_rb - borders->x_lt) / 2 + borders->x_lt;
	*old_cen_y = (borders->y_rt - borders->y_lb) / 2 + borders->y_lb;
	free(borders);
}

void	small_culc(t_image *image, int *step, double *part)
{
	t_fileview	*fileview;

	fileview = image->winsets->fileview;
	*step = image->lines_step;
	*part = 2 * *step / max_height(fileview);
}

void	borders_to_image(t_image *image, t_map_borders *m_brs, t_centres *cs)
{
	image->x_shift = cs->cur_cen_x - cs->old_cen_x;
	image->y_shift = cs->cur_cen_y - cs->old_cen_y;
	image->bor_x_min = m_brs->bor_min_x;
	image->bor_y_min = m_brs->bor_min_y;
	image->bor_x_max = m_brs->bor_max_x;
	image->bor_y_max = m_brs->bor_max_y;
}

void	figure_res(t_image *image, t_map_borders *m_brs)
{
	t_centres	*cs;
	t_borders	*borders;
	double		mult;
	int			step;
	double		part;

	cs = (t_centres*)malloc(sizeof(t_centres));
	cs->cur_cen_x = (m_brs->bor_max_x - m_brs->bor_min_x);
	cs->cur_cen_x = cs->cur_cen_x / 2 + m_brs->bor_min_x;
	cs->cur_cen_y = (m_brs->bor_max_y - m_brs->bor_min_y);
	cs->cur_cen_y = cs->cur_cen_y / 2 + m_brs->bor_min_y;
	mult = 0;
	small_culc(image, &step, &part);
	borders = (t_borders*)malloc(sizeof(t_borders));
	b_mult(image, borders, &cs->old_cen_x, &cs->old_cen_y);
	mult = (double)(m_brs->bor_max_x - m_brs->bor_min_x);
	mult = mult / (double)(borders->x_rb - borders->x_lt);
	image->mult = (mult != image->mult) ? mult : image->mult;
	mult = (double)(m_brs->bor_max_y - m_brs->bor_min_y);
	mult = mult / (double)(borders->y_rt - borders->y_lb);
	image->mult = (mult < image->mult) ? mult : image->mult;
	after_mult(part, image, &cs->old_cen_x, &cs->old_cen_y);
	borders_to_image(image, m_brs, cs);
	free(borders);
	free(cs);
}
