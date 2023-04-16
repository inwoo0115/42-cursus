/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:17:28 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/16 21:18:44 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_error(int error)
{
	perror(strerror(error));
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_data	img;

	init_data(argc, argv, &img);
	img.mlx = mlx_init();
	if (!img.mlx)
		ft_error(ENOMEM);
	img.win = mlx_new_window(img.mlx, 1000, 1000, "fractol");
	if (!img.win)
		ft_error(ENOMEM);
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_len, &img.endian);
	ft_set_hook(&img);
	ft_put_image(&img);
	mlx_loop_hook(img.mlx, ft_put_image, &img);
	mlx_loop(img.mlx);
}
