/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:51:17 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:51:18 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char c, va_list *list)
{
	if (c == 'c')
		return (ft_printf_char(va_arg(*list, int)));
	else if (c == 's')
		return (ft_printf_str(va_arg(*list, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_printf_nbr(va_arg(*list, int)));
	else if (c == 'u')
		return (ft_printf_unsigned(va_arg(*list, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_printf_hex(va_arg(*list, unsigned int), c));
	else if (c == 'p')
		return (ft_printf_ptr(va_arg(*list, unsigned long long)));
	else if (c == '%')
		return (ft_printf_char('%'));
	return (0);
}

int	ft_error_printf(const char *format, ...)
{
	int		len;
	int		idx;
	va_list	list;

	va_start(list, format);
	len = 0;
	idx = 0;
	while (format[idx])
	{
		if (format[idx] == '%')
		{
			len += check_type(format[idx + 1], &list);
			idx++;
		}
		else
			len += ft_printf_char(format[idx]);
		idx++;
	}
	va_end(list);
	return (len);
}
