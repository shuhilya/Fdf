/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:03:34 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 18:03:36 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	first_sets(t_image *image)
{
	t_angles	*angles;
	t_point		*center;

	image->x_size = 2000;
	image->y_size = 1000;
	image->out_lines = (t_line*)malloc(sizeof(t_line));
	angles = (t_angles*)malloc(sizeof(angles));
	angles->ang_x = 0;
	angles->ang_y = 0;
	angles->ang_z = 0;
	image->x_shift = 0;
	image->y_shift = 0;
	image->x_zero = 0;
	image->y_zero = 0;
	image->angles = angles;
	image->mult = 1;
	image->color = 0xFF;
	center = (t_point*)malloc(sizeof(t_point));
	center->x = 60;
	center->y = 100;
	center->z = 20;
	image->center = center;
	image->height = 1;
	image->res_interface = 1;
}

void	general_color_sets(t_image *image)
{
	image->base_color = 0xFF0000;
	image->top_color = 0xFFFF00;
	image->main_color = 0x00FF00;
	image->ground_col = 0x00FF00;
	image->col_top_flag = 0;
	image->col_bot_flag = 0;
}

void	second_sets(t_image *image, t_winsets *winsets, double st, double ht)
{
	int		bpp;
	int		sl;
	int		enin;
	char	*data;
	t_line	*lines;

	bpp = 8;
	sl = 400;
	enin = 0;
	data = mlx_get_data_addr(winsets->img_ptr, &bpp, &sl, &enin);
	image->ptr_image = winsets->img_ptr;
	image->mlx_ptr = winsets->mlx_ptr;
	image->win_ptr = winsets->win_ptr;
	image->data_image = data;
	lines = calc_lines(winsets->fileview, st, ht);
	image->base_lines = lines;
	image->angle_flag = 1;
	image->col_map_y = 100;
	image->col_map_x = 1700;
	image->glob_mode = 1;
	image->col_mode = 0;
	image->help_mode = 0;
	image->plus_to_minus = 1;
	image->minus_to_plus = 0;
	general_color_sets(image);
}

void	v(char *tmp, int *i)
{
	if (tmp[1] && tmp[2] && tmp[1] == '0' && tmp[2] == 'x')
	{
		while (*i < 9)
		{
			if (!(tmp[*i] >= '0' && tmp[*i] <= '9') &&
				!((tmp[*i] >= 'A' && tmp[*i] <= 'F') ||
				(tmp[*i] >= 'a' && tmp[(*i)++] <= 'f')))
				user_instr(4, "");
			(*i)++;
		}
	}
}
