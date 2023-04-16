/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fractol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:04:48 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/16 21:21:34 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(double a, double b)
{
	double	tmpx;
	double	x;
	double	y;
	int		i;

	x = 0.0;
	y = 0.0;
	i = 0;
	while (i < 100 && x * x + y * y <= 2 * 2)
	{
		tmpx = x;
		x = x * x - y * y + a;
		y = 2.0 * tmpx * y + b;
		i++;
	}
	return (i);
}

int	ft_julia(double x, double y, t_data *img)
{
	double	tmpx;
	int		i;

	i = 0;
	while (i < 100 && x * x + y * y <= 2 * 2)
	{
		tmpx = x;
		x = x * x - y * y + img->rnum;
		y = 2.0 * tmpx * y + img->inum;
		i++;
	}
	return (i);
}
