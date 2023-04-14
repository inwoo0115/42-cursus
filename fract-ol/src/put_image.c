/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:42:30 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/14 21:54:20 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	put_color(int i, int color)
{
	int	depth;

	depth = 0;
	if (i > 80)
		depth += 200 << 8;
	if (i > 60)
		depth += 200 << 16;
	if (i > 40)
		depth += 200;
	return (depth + color);
}

int	ft_put_image(t_data *img)
{
	double	x;
	double	y;
	int		color;

	x = 0.0;
	while (x < 1000)
	{
		y = 0.0;
		while (y < 1000)
		{
			color = ft_fractol(img, img->type, x, y);
			pixel_put(img, x, y, put_color(color, img->color));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

int	ft_fractol(t_data *img, int type, double x, double y)
{
	int	color;

	color = 0;
	if (type == MANDEL)
		color = ft_mandelbrot((x - img->midx) * (img->scale / 1000), \
		(y - img->midy) * (img->scale / 1000));
	if (type == JULIA)
		color = ft_julia((x - img->midx) * (img->scale / 1000), \
		(y - img->midy) * (img->scale / 1000), img);
	return (color);
}

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
