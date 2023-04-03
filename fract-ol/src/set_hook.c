/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:47:06 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/03 22:57:38 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_hook(t_data *img)
{
	mlx_key_hook(img->win, ft_key_handler, img);
	mlx_mouse_hook(img->win, ft_mouse_handler, img);
}

int	ft_key_handler(int keycode, t_data *img)
{
	if (keycode == ESC)
	{
		exit(0);
	}
	else if (keycode == UP)
	else if (keycode == DOWN)
	else if (keycode == LEFT)
	else if (keycode == RIGHT)
	else
		return (0);
	print_img(img);
	return (0);
}

int	ft_mouse_handler(int keycode, t_data *img)
{
	if (keycode == MUP)
	{
		img->scale = img->scale * 1.1;
	}
	else if (keycode == MDOWN)
	{
		img->scale = img->scale * 0.9;
	}
	else
		return (0);
	ft_put_image(img);
	return (0);
}

void	change_scale(int direct, t_data *img)
{
	
}
