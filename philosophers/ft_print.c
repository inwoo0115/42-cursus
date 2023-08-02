/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:11:08 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/02 17:44:25 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_print(t_data *data, int action, int philo)
{
	pthread_mutex_lock(&data->sys[PRINT]);
	if (!data->death)
	{
		if (action == EAT)
			printf("%lld %d is eating\n", get_time() - data->t_start, philo);
		else if (action == SLEEP)
			printf("%lld %d is sleeping\n", get_time() - data->t_start, philo);
		else if (action == THINK)
			printf("%lld %d is thinking\n", get_time() - data->t_start, philo);
		else if (action == FORK)
			printf("%lld %d has taken fork\n", \
			get_time() - data->t_start, philo);
		else if (action == DIE)
		{
			printf("%lld %d died\n", get_time() - data->t_start, philo);
			data->death = 1;
		}
		else if (action == EATDONE)
		{
			printf("%lld finish eating!\n", get_time() - data->t_start);
			data->death = 1;
		}
	}
	pthread_mutex_unlock(&data->sys[PRINT]);
}
