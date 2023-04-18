/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:47:06 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/17 16:51:42 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_exit(void)
{
	exit(0);
}

void	ft_set_hook(t_data *img)
{
	mlx_key_hook(img->win, ft_key_handler, img);
	mlx_mouse_hook(img->win, ft_mouse_handler, img);
	mlx_hook(img->win, 17, 0, ft_exit, img);
}

int	ft_key_handler(int keycode)
{
	if (keycode == ESC)
		exit(0);
	return (0);
}

int	ft_mouse_handler(int keycode, int x, int y, t_data *img)
{
	img->mx = (double)x;
	img->my = (double)y;
	if (keycode == MUP)
		img->scale = img->scale * 1.05;
	else if (keycode == MDOWN)
		img->scale = img->scale * 0.95;
	else
		return (0);
	return (0);
}
