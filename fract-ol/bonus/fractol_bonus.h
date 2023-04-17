/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:16:41 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/17 16:07:27 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <math.h>

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
	int		color;
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
	BURN = 3,
	RED = 12,
	BLUE = 13,
	GREEN = 14,
	RKEY = 15,
	GKEY = 5,
	BKEY = 11,
};

//fractol.c
void	ft_error(int error);

//init.c
void	init_data(int argc, char *argv[], t_data *img);
int		check_type(int argc, char *argv[], t_data *img);
int		parsing_type(char *argv[], char *type);
double	check_num(char	*str, double sign_fraction, double decimal);

//put_image
void	pixel_put(t_data *data, int x, int y, int color);
int		ft_put_image(t_data *img);
int		ft_fractol(t_data *img, int type, double x, double y);
int		put_color(int i, int color);

//put_fractol
int		ft_mandelbrot(double a, double b);
int		ft_julia(double x, double y, t_data *img);
int		ft_burningship(double a, double b);

//set_hook
void	ft_set_hook(t_data *img);
int		ft_key_handler(int keycode, t_data *img);
int		ft_mouse_handler(int keycode, int x, int y, t_data *img);
void	change_scale(int keycode, t_data *img);

#endif