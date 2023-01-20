/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:04:32 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/20 20:52:42 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(void *ptr)
{
	uintptr_t		num;
	int				len;

	num = (uintptr_t)(ptr);
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

int	print_udec(unsigned int num)
{
	int	len;

	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	len = ft_itoa(num);
	return (len);
}

int	print_lhex(unsigned int num)
{
	int	len;

	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	len = ft_lhex(num);
	return (len);
}

int	print_uhex(unsigned int num)
{
	int	len;

	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	len = ft_uhex(num);
	return (len);
}
