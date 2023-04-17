/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:08:48 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/17 15:44:28 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(int argc, char *argv[], t_data *img)
{
	if (argc <= 1 || !check_type(argc, argv, img))
	{
		printf("Please input right argument\n");
		printf("1. mandelbrot\n");
		printf("2. julia [real number] [imaginary number]\n");
		exit (0);
	}
	img->midx = 500.0;
	img->midy = 500.0;
	img->scale = 3.0;
	img->color = 0;
}

int	check_type(int argc, char *argv[], t_data *img)
{
	if (parsing_type(argv, "mandelbrot") && argc == 2)
		img->type = MANDEL;
	else if (parsing_type(argv, "julia"))
	{
		if (argc != 4)
			return (0);
		img->type = JULIA;
		img->rnum = check_num(argv[2], 10.0, 0.0);
		img->inum = check_num(argv[3], 10.0, 0.0);
		if (img->rnum > 10 || img->inum > 10)
			return (0);
	}
	else
		return (0);
	return (1);
}

int	parsing_type(char *argv[], char *type)
{
	int	i;

	i = 0;
	while (type[i] && argv[1][i])
	{
		if (argv[1][i] != type[i])
			return (0);
		i++;
	}
	if (argv[1][i] || type[i])
		return (0);
	return (1);
}

double	check_num(char	*str, double sign_fraction, double decimal)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign_fraction = -10;
		str++;
	}
	if (*str == '0')
		str++;
	else
		return (100.0);
	if (*str == '.')
	{
		str++;
		if (!(*str))
			return (100.0);
		while (*str >= '0' && *str <= '9')
		{
			decimal += (double)(*str - '0') / sign_fraction;
			sign_fraction *= 10;
			str++;
		}
	}
	if (*str)
		return (100.0);
	return (decimal);
}
