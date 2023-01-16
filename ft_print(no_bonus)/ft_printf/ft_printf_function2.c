/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:58:12 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/16 23:02:27 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_itoa(long long num)
{
	int		len;
	char	c;

	len = 0;
	if (num == 0)
		return (0);
	len++;
	len += ft_itoa(num / 10);
	c = num % 10 + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (len);
}

int	ft_lhex(unsigned int num)
{
	int		len;
	char	*str;

	str = "0123456789abcdef";
	len = 0;
	if (num == 0)
		return (0);
	len++;
	len += ft_itoa(num / 16);
	if (write(1, &str[num % 16], 1) == -1)
		return (-1);
	return (len);
}

int	ft_uhex(unsigned int num)
{
	int		len;
	char	*str;

	str = "0123456789ABCDEF";
	len = 0;
	if (num == 0)
		return (0);
	len++;
	len += ft_itoa(num / 16);
	if (write(1, &str[num % 16], 1) == -1)
		return (-1);
	return (len);
}
