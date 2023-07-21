/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:51:26 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:51:27 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pputnbr_base(long long nb, char *base)
{
	int		len;

	len = ft_pstrlen(base);
	if (nb < 0)
	{
		ft_pputchar_fd('-', 2);
		nb *= -1;
	}
	if (nb < len)
	{
		ft_pputchar_fd(base[nb], 2);
	}
	if (nb >= len)
	{
		ft_pputnbr_base(nb / len, base);
		ft_pputnbr_base(nb % len, base);
	}
	return (n_count(nb, len));
}
