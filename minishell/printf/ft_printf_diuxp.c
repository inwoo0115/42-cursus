/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diuxp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:51:15 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:51:15 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_nbr(int nbr)
{
	int		len;
	char	*str;

	str = ft_pitoa(nbr);
	len = ft_pputstr_fd(str, 2);
	free(str);
	return (len);
}

int	ft_printf_unsigned(unsigned int nbr)
{
	int		len;
	char	*str;

	str = ft_pitoa(nbr);
	len = ft_pputstr_fd(str, 2);
	free(str);
	return (len);
}

int	ft_printf_hex(unsigned int nbr, const char type)
{
	size_t	len;

	len = 0;
	if (type == 'x')
		len = ft_pputnbr_base(nbr, "0123456789abcdef");
	else
		len = ft_pputnbr_base(nbr, "0123456789ABCDEF");
	return (len);
}

static void	ft_putptr(unsigned long long ptr, size_t *len)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16, len);
		ft_putptr(ptr % 16, len);
	}
	else
	{
		if (ptr < 10)
			*len += ft_pputchar_fd('0' + ptr, 2);
		else
			*len += ft_pputchar_fd(ptr - 10 + 'a', 2);
	}
}

int	ft_printf_ptr(unsigned long long ptr)
{
	size_t	len;

	len = 0;
	len += 2;
	write(2, "0x", len);
	ft_putptr(ptr, &len);
	return (len);
}
