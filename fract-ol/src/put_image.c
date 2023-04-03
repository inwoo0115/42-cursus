/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:42:30 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/03 22:37:13 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_put_image(t_data *img)
{
	double	x;
	double	y;

	x = 0.0;
	y = 0.0;
	while (x < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			if (ft_mandelbrot(img, (x - img.midx) / img.scale, \
			(y - img.midy) / img.scale))
				pixel_put(img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	ft_mandelbrot(t_data *img, double a, double b)
{
	double	tmpx;
	double	x;
	double	y;
	int		i;

	x = 0.0;
	y = 0.0;
	i = 0;
	while (i < 1000 && x * x + y * y <= 2 * 2)
	{
		tmpx = x;
		x = x * x - y * y + a;
		y = 2.0 * tmpx * y + b;
		i++;
	}
	if (i == 1000)
		return (1);
	return (0);
}
