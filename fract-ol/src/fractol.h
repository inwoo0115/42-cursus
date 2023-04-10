/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:16:41 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/10 21:54:55 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		type;
	double	mx;
	double	my;
	double	midx;
	double	midy;
	double	scale;
	double	rnum;
	double	inum;
}	t_data;

enum e_key
{
	ESC = 53,
	UP = 126,
	DOWN = 125,
	LEFT = 123,
	RIGHT = 124,
	MDOWN = 5,
	MUP = 4,
	MANDEL = 1,
	JULIA = 2,
	WIDTH = 1000,
	HEIGHT = 1000,
};

//fractol.c
void	ft_error(int error);

//init.c
void	init_data(int argc, char *argv[], t_data *img);
int		check_type(int argc, char *argv[], t_data *img);
int		parsing_type(char *argv[], char *type);
double	check_num(char	*num);

//put_image
void	pixel_put(t_data *data, int x, int y, int color);
int		ft_put_image(t_data *img);
int		ft_mandelbrot(double a, double b);

//set_hook
void	ft_set_hook(t_data *img);
int		ft_key_handler(int keycode, t_data *img);
int		ft_mouse_handler(int keycode, int x, int y, t_data *img);
void	change_scale(int keycode, t_data *img);
#endif