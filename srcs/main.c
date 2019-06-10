/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:59:26 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 17:59:30 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	wh_chs(t_image *image, int clear_fl, t_angles *angles, t_line *start)
{
	t_line		*one_line;

	one_line = (t_line*)malloc(sizeof(t_line));
	if (!clear_fl)
	{
		start->zd0 = start->zd0 * image->height;
		start->zd1 = start->zd1 * image->height;
	}
	assigm_x(start, image->out_lines, angles->ang_x, image->center);
	line_copy(image->out_lines, one_line);
	assigm_y(one_line, image->out_lines, angles->ang_y, image->center);
	line_copy(image->out_lines, one_line);
	assigm_z(one_line, image->out_lines, angles->ang_z, image->center);
	line_copy(image->out_lines, one_line);
	zoom(one_line, image->mult);
	set_line(one_line, image->x_zero, image->y_zero, image);
	if (clear_fl)
	{
		start->zd0 = start->zd0 / image->height;
		start->zd1 = start->zd1 / image->height;
	}
	free(one_line);
}

void	set_all(t_image *im, int clear_fl)
{
	t_line		*start;
	t_angles	*angles;

	if ((!clear_fl) && (im->res_interface))
	{
		set_borders(im);
		im->res_interface = 0;
	}
	angles = im->angles;
	start = im->base_lines;
	while (start != NULL)
	{
		wh_chs(im, clear_fl, angles, start);
		start = start->next;
	}
	mlx_clear_window(im->mlx_ptr, im->win_ptr);
	mlx_put_image_to_window(im->mlx_ptr, im->win_ptr, im->ptr_image, 0, 0);
	set_interfaces(im);
}

void	part_main(t_image *image, char *filename, t_winsets *winsets)
{
	int				fd;
	int				y;
	t_map_borders	*map_borders;
	t_fileview		*fileview;

	fileview = (t_fileview *)malloc(sizeof(t_fileview));
	map_borders = (t_map_borders *)malloc(sizeof(map_borders));
	image->map_borders = map_borders;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		user_instr(2, filename);
	}
	y = ft_y(fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	reader(fd, y, fileview);
	winsets->fileview = fileview;
	set_glob_pos(image, fileview, winsets);
	map_borders->bor_min_x = 0;
	map_borders->bor_min_y = 0;
	map_borders->bor_max_x = 2000;
	map_borders->bor_max_y = 1000;
	figure_res(image, map_borders);
	set_all(image, 0);
}

int		main(int argc, char **argv)
{
	t_winsets	*win;
	t_image		*im;
	char		*filename;

	if (argc != 2)
		user_instr(1, "");
	filename = argv[1];
	im = (t_image*)malloc(sizeof(t_image));
	first_sets(im);
	win = (t_winsets*)malloc(sizeof(t_winsets));
	im->winsets = win;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, im->x_size, im->y_size, "fdf");
	win->img_ptr = mlx_new_image(win->mlx_ptr, im->x_size, im->y_size);
	part_main(im, filename, win);
	mlx_clear_window(im->mlx_ptr, im->win_ptr);
	mlx_put_image_to_window(im->mlx_ptr, im->win_ptr, im->ptr_image, 0, 0);
	glob_interface(im);
	mlx_hook(win->win_ptr, 2, 0, key_press, (void*)im);
	mlx_hook(win->win_ptr, 4, 0, mouse_press, (void*)im);
	mlx_hook(win->win_ptr, 5, 0, mouse_release, (void*)im);
	mlx_hook(win->win_ptr, 6, 0, mouse_move, (void*)im);
	mlx_hook(win->win_ptr, 17, 0, ft_close, (void*)0);
	mlx_loop(win->mlx_ptr);
	return (0);
}
