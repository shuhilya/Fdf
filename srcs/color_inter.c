/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:00:11 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 18:00:14 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ci_str1(t_image *image, int x, int y)
{
	char	*s;
	int		c;

	c = 0xFFFFFF;
	s = "Base color gradient:";
	mlx_string_put(image->mlx_ptr, image->win_ptr, 1698, 390, c, s);
	s = "Base color map:";
	mlx_string_put(image->mlx_ptr, image->win_ptr, 1698, 70, c, s);
	s = "- top color";
	mlx_string_put(image->mlx_ptr, image->win_ptr, 1728, 460, c, s);
	s = "- bottom color";
	mlx_string_put(image->mlx_ptr, image->win_ptr, 1728, 500, c, s);
	s = "To choose base color use keys:";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y, c, s);
	s = "1. 'R' - for red base";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x + 15, y + 20, c, s);
	s = "2. 'G' - for green base";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x + 15, y + 40, c, s);
	s = "3. 'B' - for blue base";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x + 15, y + 60, c, s);
}

void	ci_str2(t_image *image, int x, int y)
{
	char	*s;
	int		c;

	c = 0xFFFFFF;
	ci_str1(image, x, y);
	s = "To set top color use key 'H' and then";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 100, 0xFFFFFF, s);
	s = "click at the choosen color on the color map.";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 120, 0xFFFFFF, s);
	s = "To set bottom color use key 'L' and then";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 160, 0xFFFFFF, s);
	s = "click at the choosen color on the color map.";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 180, 0xFFFFFF, s);
	s = "To set base color hue click at the ";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 220, 0xFFFFFF, s);
	s = "choosen color on the color gradient.";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 240, 0xFFFFFF, s);
	s = "To show color changes use key 'S'.";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 280, 0xFFFFFF, s);
	s = "To exit use 'E'.";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 320, 0xFFFFFF, s);
}

void	color_interface(t_image *image)
{
	int i;
	int pos_x;
	int pos_y;

	i = 0;
	while (i < 1000)
	{
		mlx_pixel_put(image->mlx_ptr, image->win_ptr, 1140, i, 0xFFFFFF);
		i++;
	}
	pos_x = 1200;
	pos_y = 70;
	ci_str1(image, pos_x, pos_y);
	ci_str2(image, pos_x, pos_y);
}
