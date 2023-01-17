/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:14:39 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/17 21:39:08 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_itoa(long long num)
{
	int		len;
	int		result;
	char	c;

	len = 0;
	if (num == 0)
		return (0);
	len++;
	result = ft_itoa(num / 10);
	if (result == -1)
		return (-1);
	len += result;
	c = num % 10 + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len);
}

int	ft_lhex(unsigned long num)
{
	int		len;
	int		result;
	char	*str;

	str = "0123456789abcdef";
	len = 0;
	if (num == 0)
		return (0);
	len++;
	result = ft_lhex(num / 16);
	if (result == -1)
		return (-1);
	len += result;
	if (write(1, &(str[num % 16]), 1) == -1)
		return (-1);
	return (len);
}

int	ft_uhex(unsigned long num)
{
	int		len;
	int		result;
	char	*str;

	str = "0123456789ABCDEF";
	len = 0;
	if (num == 0)
		return (0);
	len++;
	result = ft_uhex(num / 16);
	if (result == -1)
		return (-1);
	len += result;
	if (write(1, &(str[num % 16]), 1) == -1)
		return (-1);
	return (len);
}
