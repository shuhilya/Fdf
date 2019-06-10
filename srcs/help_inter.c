/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_inter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htorp <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:00:41 by htorp             #+#    #+#             */
/*   Updated: 2019/02/19 18:00:46 by htorp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hi_str1(t_image *image, int x, int y)
{
	char	*s;
	int		c;

	c = 0xFFFFFF;
	s = "To move figure:";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y, c, s);
	s = "1. Use mouse left button;";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 20, c, s);
	s = "2. Use keys:";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 40, c, s);
	s = "2.1. 'W' - for up";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x + 15, y + 60, c, s);
	s = "2.2. 'S' - for down";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x + 15, y + 80, c, s);
	s = "2.3. 'W' - for up";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x + 15, y + 100, c, s);
	s = "2.4. 'D' - for right;";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x + 15, y + 120, c, s);
	s = "To change scale:";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 140, c, s);
	s = "1. Use mouse scroll;";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 160, c, s);
	s = "2. Use keys:";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 180, c, s);
}

void	hi_str2(t_image *image, int x, int y)
{
	char	*s;
	int		c;

	c = 0xFFFFFF;
	s = "2.1. '+' - for increase,";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x + 15, y + 200, c, s);
	s = "2.2. '-' - for decrease";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x + 15, y + 220, c, s);
	s = "To change height use keys:";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 240, c, s);
	s = "1. 'H' - for increase";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x + 15, y + 260, c, s);
	s = "2. 'L' - for decrease";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x + 15, y + 280, c, s);
	s = "To set rotation axis use keys:";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 300, c, s);
	s = "1. 'X' - for x";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x + 15, y + 320, c, s);
	s = "2. 'Y' - for y";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x + 15, y + 340, c, s);
	s = "3. 'Z' - for z";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x + 15, y + 360, c, s);
	s = "To change rotation direction use key 'Control';";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 380, c, s);
}

void	hi_str3(t_image *image, int x, int y)
{
	char	*s;
	int		c;

	c = 0xFFFFFF;
	s = "To set user color use key 'U';";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 400, c, s);
	s = "To set default color use key 'B';";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 420, c, s);
	s = "To open 'Color mode' use key 'C';";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 440, c, s);
	s = "To close program use key 'Esc';";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 460, c, s);
	s = "To exit use key 'E'.";
	mlx_string_put(image->mlx_ptr, image->win_ptr, x, y + 480, c, s);
}

void	help_interface(t_image *image)
{
	int i;
	int y;
	int x;

	i = 0;
	y = 230;
	x = 1520;
	while (i < 1000)
	{
		mlx_pixel_put(image->mlx_ptr, image->win_ptr, 1500, i, 0xFFFFFF);
		i++;
	}
	hi_str1(image, x, y);
	hi_str2(image, x, y);
	hi_str3(image, x, y);
}
