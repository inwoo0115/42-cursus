/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:00:58 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/01 21:13:19 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_function(t_data *data)
{
	int	i;

	data->index++;
	i = data->index;
	philo_init(data, &(data->info[i - 1]), i);
	pthread_mutex_lock(&(data->sys[THINK]));
	pthread_mutex_unlock(&(data->sys[THINK]));
	if (i % 2 == 0)
	{
		ft_thinking(data, i);
		usleep(data->t_eat * 500);
	}
	while (data->death == 0)
	{
		ft_eating(data, i);
		ft_sleeping(data, i);
		ft_thinking(data, i);
	}
	return ;
}

int	ft_eating(t_data *data, int i)
{
	pthread_mutex_lock(&data->fork[data->info[i - 1].first]);
	thread_print(data, FORK, i);
	pthread_mutex_lock(&data->fork[data->info[i - 1].second]);
	thread_print(data, FORK, i);
	pthread_mutex_lock(&(data->sys[EAT]));
	data->info[i - 1].last_eat = get_time();
	pthread_mutex_unlock(&(data->sys[EAT]));
	thread_print(data, EAT, i);
	while (get_time() - data->info[i - 1].last_eat < (unsigned long)data->t_eat)
		usleep(1);
	pthread_mutex_unlock(&data->fork[data->info[i - 1].first]);
	pthread_mutex_unlock(&data->fork[data->info[i - 1].second]);
	data->info[i - 1].eat_time++;
	if (data->info[i - 1].eat_time == data->must_eat)
		data->death = 1;
	return (0);
}

int	ft_sleeping(t_data *data, int i)
{
	size_t	now;

	thread_print(data, SLEEP, i);
	now = get_time();
	while (get_time() - now < (unsigned long)data->t_sleep)
		usleep(1);
	return (0);
}

int	ft_thinking(t_data *data, int i)
{
	thread_print(data, THINK, i);
	return (0);
}
