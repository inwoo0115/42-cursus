/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:54:36 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/01 21:07:35 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_monitoring(t_data *data)
{
	int	i;

	pthread_mutex_lock(&(data->sys[THINK]));
	pthread_mutex_unlock(&(data->sys[THINK]));
	while (data->death == 0)
	{
		i = 0;
		pthread_mutex_lock(&(data->sys[EAT]));
		while (i < data->philo_num)
		{
			if (get_time() - data->info[i].last_eat > \
			(unsigned long)data->t_die)
				thread_print(data, DIE, i + 1);
			i++;
		}
		pthread_mutex_unlock(&(data->sys[EAT]));
		usleep(50);
	}
	return ;
}

size_t	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}
