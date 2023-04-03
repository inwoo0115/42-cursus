/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:16:41 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/03 22:36:30 by wonjilee         ###   ########.fr       */
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
	WIDTH = 1000;
	HEIGHT = 1000;
};

#endif