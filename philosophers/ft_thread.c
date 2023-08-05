/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:00:58 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/05 20:16:12 by wonjilee         ###   ########.fr       */
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
	while (1)
	{
		if (!check_death(data))
			break ;
		if (!ft_eating(data, i))
			break ;
		if (!ft_sleeping(data, i))
			break ;
		if (!ft_thinking(data, i))
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
		if (!eating_time(data, i))
		{
			pthread_mutex_unlock(&data->fork[data->info[i - 1].first]);
			pthread_mutex_unlock(&data->fork[data->info[i - 1].second]);
			return (0);
		}
		pthread_mutex_unlock(&data->fork[data->info[i - 1].first]);
		pthread_mutex_unlock(&data->fork[data->info[i - 1].second]);
		return (1);
	}
	pthread_mutex_unlock(&data->fork[data->info[i - 1].first]);
	return (0);
}

int	ft_sleeping(t_data *data, int i)
{
	size_t	now;

	thread_print(data, SLEEP, i);
	now = get_time();
	while (get_time() - now < (size_t)data->t_sleep)
	{
		if (!check_death(data))
			return (0);
		usleep(100);
	}
	return (1);
}

int	ft_thinking(t_data *data, int i)
{
	if (!check_death(data))
		return (0);
	thread_print(data, THINK, i);
	return (1);
}

int	check_death(t_data *data)
{
	pthread_mutex_lock(&data->sys[FLAG]);
	if (data->death != 0)
	{
		pthread_mutex_unlock(&data->sys[FLAG]);
		return (0);
	}
	pthread_mutex_unlock(&data->sys[FLAG]);
	return (1);
}
