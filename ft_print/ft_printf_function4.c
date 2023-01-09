/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:48:10 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/09 19:48:40 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_convert(t_convert *text, va_list ap)
{
	if (text->index == PLAIN)
		return (print_plain(text));
	else if (text->index == CHAR)
		return (print_char(text, va_arg(ap, int)));
	else if (text->index == STR)
		return (print_str(text, va_arg(ap, char *)));
	else if (text->index == PTR)
		return (print_ptr(text, va_arg(ap, void *)));
	else if (text->index == DEC)
		return (print_dec(text, va_arg(ap, int)));
	else if (text->index == IDEC)
		return (print_idec(text, va_arg(ap, int)));
	else if (text->index == UDEC)
		return (print_udec(text, va_arg(ap, int)));
	else if (text->index == LHEX)
		return (print_lhex(text, va_arg(ap, int)));
	else if (text->index == UHEX)
		return (print_uhex(text, va_arg(ap, int)));
	else if (text->index == PCENT)
		return (print_pcent(text));
	return (-1);
}

int	check_flags(char **locate)
{
	locate++;
	if (*locate == 'c')
		return (CHAR);
	else if (*locate == 's')
		return (STR);
	else if (*locate == 'p')
		return (PTR);
	else if (*locate == 'd')
		return (DEC);
	else if (*locate == 'i')
		return (IDEC);
	else if (*locate == 'u')
		return (UDEC);
	else if (*locate == 'x')
		return (LHEX);
	else if (*locate == 'X')
		return (UHEX);
	else if (*locate == '%')
		return (PCENT);
	else
		return (-1);
}
