/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:04:32 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/16 23:13:49 by wonjilee         ###   ########.fr       */
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
	if (!str)
		return (-1);
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
	unsigned int	num;
	int				len;

	if (!ptr)
		return (-1);
	num = (unsigned int)ptr;
	len = ft_lhex(num);
	return (len);
}

int	print_dec(int num)
{
	int			len;
	long long	n;

	len = 0;
	n = (long long)num;
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = (long long)num * (-1);
		len++;
	}
	len = ft_itoa(n);
	return (len);
}

int	print_int(int num)
{
	int			len;
	long long	n;

	len = 0;
	n = (long long)num;
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = (long long)num * (-1);
		len++;
	}
	len = ft_itoa(n);
	return (len);
}

int	print_udec(unsigned int num)
{
	int	len;

	len = ft_itoa(num);
	return (len);
}

int	print_lhex(unsigned int num)
{
	int	len;

	len = ft_lhex(num);
	return (len);
}

int	print_uhex(unsigned int num)
{
	int	len;

	len = ft_uhex(num);
	return (len);
}

int	print_pcent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
