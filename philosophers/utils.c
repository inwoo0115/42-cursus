/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:18:33 by wonjilee          #+#    #+#             */
/*   Updated: 2023/06/06 21:27:05 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + (str[i++] - '0');
		else
		{
			write(2, "Not correct argument", 20);
			exit(1);
		}
	}
	return (num);
}
