/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:47:06 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/16 21:31:48 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_set_hook(t_data *img)
{
	mlx_key_hook(img->win, ft_key_handler, img);
	mlx_mouse_hook(img->win, ft_mouse_handler, img);
}

int	ft_key_handler(int keycode, t_data *img)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == UP)
		img->midy -= 10.0;
	else if (keycode == DOWN)
		img->midy += 10.0;
	else if (keycode == LEFT)
		img->midx -= 10.0;
	else if (keycode == RIGHT)
		img->midx += 10.0;
	else if (keycode == RKEY)
		img->color = 32 << 16;
	else if (keycode == GKEY)
		img->color = 32 << 8;
	else if (keycode == BKEY)
		img->color = 32;
	return (0);
}

int	ft_mouse_handler(int keycode, int x, int y, t_data *img)
{
	img->mx = (double)x;
	img->my = (double)y;
	if (keycode == MUP)
	{
		img->scale = img->scale * 1.05;
		change_scale(MUP, img);
	}
	else if (keycode == MDOWN)
	{
		img->scale = img->scale * 0.95;
		change_scale(MDOWN, img);
	}
	else
		return (0);
	return (0);
}

void	change_scale(int keycode, t_data *img)
{
	if (keycode == MDOWN)
	{
		img->midx = (20.0 * img->midx - img->mx) / (20.0 - 1.0);
		img->midy = (20.0 * img->midy - img->my) / (20.0 - 1.0);
	}
	else if (keycode == MUP)
	{
		img->midx = (20.0 * img->midx + img->mx) / (20.0 + 1.0);
		img->midy = (20.0 * img->midy + img->my) / (20.0 + 1.0);
	}
}
