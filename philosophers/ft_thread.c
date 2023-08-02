/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:00:58 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/02 18:06:12 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_function(t_data *data)
{
	int	i;

	pthread_mutex_lock(&(data->sys[START]));
	i = get_index(data) + 1;
	pthread_mutex_unlock(&(data->sys[START]));
	if (i % 2 == 0)
	{
		ft_thinking(data, i);
		usleep(data->t_eat * 500);
	}
	while (data->death == 0)
	{
		if (ft_eating(data, i))
		{
			ft_sleeping(data, i);
			ft_thinking(data, i);
		}
		else
			break ;
	}
	return ;
}

int	ft_eating(t_data *data, int i)
{
	pthread_mutex_lock(&data->fork[data->info[i - 1].first]);
	thread_print(data, FORK, i);
	if (data->philo_num != 1)
	{
		pthread_mutex_lock(&data->fork[data->info[i - 1].second]);
		thread_print(data, FORK, i);
		pthread_mutex_lock(&(data->sys[EAT]));
		data->info[i - 1].last_eat = get_time();
		data->info[i - 1].eat_time++;
		pthread_mutex_unlock(&(data->sys[EAT]));
		thread_print(data, EAT, i);
		while (get_time() - data->info[i - 1].last_eat < (long long)data->t_eat)
			usleep(100);
		pthread_mutex_unlock(&data->fork[data->info[i - 1].first]);
		pthread_mutex_unlock(&data->fork[data->info[i - 1].second]);
		return (1);
	}
	pthread_mutex_unlock(&data->fork[data->info[i - 1].first]);
	return (0);
}

int	ft_sleeping(t_data *data, int i)
{
	long long	now;

	thread_print(data, SLEEP, i);
	now = get_time();
	while (get_time() - now < (long long)data->t_sleep)
		usleep(100);
	return (0);
}

int	ft_thinking(t_data *data, int i)
{
	thread_print(data, THINK, i);
	return (0);
}

int	get_index(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if (data->index[i] == 0)
		{
			data->index[i] = 1;
			return (i);
		}
		i++;
	}
	return (-1);
}
