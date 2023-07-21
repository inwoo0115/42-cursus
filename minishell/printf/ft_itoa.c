/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:56 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:51:10 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	n_count(long long nb, int len)
{
	size_t	count;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb >= len)
	{
		nb /= len;
		count++;
	}
	count++;
	return (count);
}

char	*ft_pitoa(long long nb)
{
	size_t	count;
	char	*new;

	count = n_count(nb, 10);
	new = (char *)malloc(sizeof(char) * count + 1);
	if (!new)
		return (NULL);
	new[count] = '\0';
	if (nb < 0)
	{
		new[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		new[0] = '0';
	count--;
	while (nb)
	{
		new[count] = nb % 10 + '0';
		nb /= 10;
		count--;
	}
	return (new);
}
