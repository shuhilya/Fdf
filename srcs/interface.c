/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:00:54 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 18:00:56 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	glob_interface(t_image *image)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	c = 0xFFFFFF;
	while (i < 2000)
	{
		mlx_pixel_put(image->mlx_ptr, image->win_ptr, i, 40, c);
		i++;
	}
	s = "To show info press 'I'";
	mlx_string_put(image->mlx_ptr, image->win_ptr, 900, 10, c, s);
}

void	set_interfaces(t_image *image)
{
	if (image->glob_mode)
		glob_interface(image);
	if (image->help_mode)
		help_interface(image);
	if (image->col_mode)
		color_interface(image);
}

void	set_borders(t_image *image)
{
	if (image->glob_mode)
	{
		image->map_borders->bor_min_x = 0;
		image->map_borders->bor_min_y = 40;
		image->map_borders->bor_max_x = 2000;
		image->map_borders->bor_max_y = 1000;
		figure_res(image, image->map_borders);
	}
	if (image->help_mode)
	{
		image->map_borders->bor_min_x = 0;
		image->map_borders->bor_min_y = 0;
		image->map_borders->bor_max_x = 1500;
		image->map_borders->bor_max_y = 1000;
		figure_res(image, image->map_borders);
	}
	if (image->col_mode)
	{
		image->map_borders->bor_min_x = 0;
		image->map_borders->bor_min_y = 0;
		image->map_borders->bor_max_x = 1140;
		image->map_borders->bor_max_y = 1000;
		figure_res(image, image->map_borders);
	}
}
