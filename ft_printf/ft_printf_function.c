/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:04:32 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/17 21:39:01 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		if (write(1, &(str[i]), 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	print_ptr(void *ptr)
{
	unsigned long	num;
	int				len;

	num = (unsigned long)(ptr);
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (3);
	}
	len = ft_lhex(num) + 2;
	return (len);
}

int	print_dec(int num)
{
	int			len;
	int			pm;
	long long	n;

	pm = 0;
	n = (long long)num;
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = (long long)num * (-1);
		pm++;
	}
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	len = ft_itoa(n);
	if (len == -1)
		return (-1);
	return (len + pm);
}

int	print_int(int num)
{
	int			len;
	int			pm;
	long long	n;

	pm = 0;
	n = (long long)num;
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = (long long)num * (-1);
		pm++;
	}
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	len = ft_itoa(n);
	if (len == -1)
		return (-1);
	return (len + pm);
}
