/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:54:36 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/09 15:13:50 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_monitoring(t_data *data)
{
	int	i;
	int	eat_done;

	while (data->death == 0)
	{
		i = 0;
		eat_done = 0;
		pthread_mutex_lock(&(data->sys[EAT]));
		while (i < data->philo_num)
		{
			if (get_time() - data->info[i].last_eat > \
			(size_t)data->t_die)
				thread_print(data, DIE, i + 1);
			if (data->info[i].eat_time >= data->must_eat \
			&& data->must_eat != -1)
				eat_done++;
			i++;
		}
		if (eat_done == data->philo_num)
			thread_print(data, EATDONE, i);
		pthread_mutex_unlock(&(data->sys[EAT]));
		usleep(100);
	}
	return ;
}

size_t	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}
