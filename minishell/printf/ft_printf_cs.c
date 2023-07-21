/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:58 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:59 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pputchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_pputstr_fd(char *s, int fd)
{
	int	len;

	len = ft_pstrlen(s);
	while (*s)
		write(fd, s++, 1);
	return (len);
}

int	ft_printf_char(int c)
{
	int	len;

	len = ft_pputchar_fd(c, 2);
	return (len);
}

int	ft_printf_str(char *str)
{
	int	len;

	if (str == 0)
	{
		len = ft_pputstr_fd("(null)", 2);
		return (len);
	}
	len = ft_pputstr_fd(str, 2);
	return (len);
}
