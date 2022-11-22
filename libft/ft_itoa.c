/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 00:24:48 by wonjilee          #+#    #+#             */
/*   Updated: 2022/11/22 16:48:28 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_size(long long n, int pm)
{
	int	size;

	size = 0;
	if (pm == -1 || n == 0)
		size++;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*put_number(char *str_num, long long n, int size, int pm)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		str_num[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	if (pm < 0)
		str_num[0] = '-';
	str_num[size] = 0;
	return (str_num);
}

char	*ft_itoa(int n)
{
	int			pm;
	int			size;
	char		*str_num;
	long long	num;

	pm = 1;
	if (n < 0)
		pm = -1;
	num = (long long)n * pm;
	size = num_size(num, pm);
	str_num = (char *)malloc(size + 1);
	if (str_num == 0)
		return (0);
	put_number(str_num, num, size, pm);
	return (str_num);
}
