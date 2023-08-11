/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:11:08 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/09 15:14:33 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_print(t_data *data, int action, int philo)
{
	pthread_mutex_lock(&data->sys[PRINT]);
	if (!data->death)
	{
		if (action == EATING)
			printf("%lu %d is eating\n", get_time() - data->t_start, philo);
		else if (action == SLEEP)
			printf("%lu %d is sleeping\n", get_time() - data->t_start, philo);
		else if (action == THINK)
			printf("%lu %d is thinking\n", get_time() - data->t_start, philo);
		else if (action == FORK)
			printf("%lu %d has taken fork\n", \
			get_time() - data->t_start, philo);
		else if (action == DIE)
			finish_thread(data, DIE, philo);
		else if (action == EATDONE)
			finish_thread(data, EATDONE, philo);
	}
	pthread_mutex_unlock(&data->sys[PRINT]);
}

void	finish_thread(t_data *data, int action, int philo)
{
	if (action == DIE)
	{
		printf("%lu %d died\n", get_time() - data->t_start, philo);
		pthread_mutex_lock(&data->sys[FLAG]);
		data->death = 1;
		pthread_mutex_unlock(&data->sys[FLAG]);
	}
	else if (action == EATDONE)
	{
		printf("%lu finish eating!\n", get_time() - data->t_start);
		pthread_mutex_lock(&data->sys[FLAG]);
		data->death = 1;
		pthread_mutex_unlock(&data->sys[FLAG]);
	}
}
