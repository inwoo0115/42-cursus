/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:51:33 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:51:34 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

long long	ft_atoll(t_main *main, const char *str, int sign)
{
	long long	temp;
	long long	tmp;

	temp = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		tmp = temp;
		temp = temp * 10 + sign * (*str - '0');
		if ((!ft_isdigit(*str)) || (sign == -1 && temp > tmp) || \
		(sign == 1 && temp < tmp))
		{
			ft_error2(NOT_LL_ERROR, main->curr->cmd[1]);
			exit(255);
		}
		++str;
	}
	return (temp * sign);
}
