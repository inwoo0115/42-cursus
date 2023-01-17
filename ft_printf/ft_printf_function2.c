/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:58:12 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/17 21:39:05 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	print_pcent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
