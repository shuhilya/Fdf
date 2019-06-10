/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 03:22:42 by cfahey            #+#    #+#             */
/*   Updated: 2019/02/18 03:22:43 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap_double(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_int(int *color0, int *color1)
{
	int	c;

	c = *color0;
	*color0 = *color1;
	*color1 = c;
}

int		ipart(double x)
{
	return ((int)x);
}

int		ft_round(double x)
{
	return (ipart(x + 0.5));
}

double	fpart(double x)
{
	return (x - ipart(x));
}
