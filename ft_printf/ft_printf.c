/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:23:10 by wonjin            #+#    #+#             */
/*   Updated: 2023/01/17 22:28:56 by wonjilee         ###   ########.fr       */
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

int	print_format(va_list ap, const char *locate)
{
	if (*locate == 'c')
		return (print_char(va_arg(ap, int)));
	else if (*locate == 's')
		return (print_str(va_arg(ap, char *)));
	else if (*locate == 'p')
		return (print_ptr(va_arg(ap, void *)));
	else if (*locate == 'd')
		return (print_int(va_arg(ap, int)));
	else if (*locate == 'i')
		return (print_int(va_arg(ap, int)));
	else if (*locate == 'u')
		return (print_udec(va_arg(ap, int)));
	else if (*locate == 'x')
		return (print_lhex(va_arg(ap, int)));
	else if (*locate == 'X')
		return (print_uhex(va_arg(ap, int)));
	else if (*locate == '%')
		return (print_pcent());
	return (0);
}

int	start_print(va_list ap, const char *format)
{
	int		len;
	int		lenf;

	len = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			lenf = print_format(ap, format);
			if (lenf < 0)
				return (-1);
			len = len + lenf;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			len++;
		}
		format++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;

	va_start(ap, format);
	result = start_print(ap, format);
	va_end(ap);
	return (result);
}
