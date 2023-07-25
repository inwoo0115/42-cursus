/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:11:08 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/25 19:59:52 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_print(t_data *data, int action, int philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	now.tv_usec = now.tv_usec - data->t_start;
	pthread_mutex_lock(&data->sys[PRINT]);
	if (action == EAT)
	{
	}
	else if (action == SLEEP)
	{
	}
	else if (action == THINK)
	{
	}
	else if (action == FORK)
	{
	}
	else if (action == DIE)
	{
	}
	pthread_mutex_unlock(&data->sys[PRINT]);
}
