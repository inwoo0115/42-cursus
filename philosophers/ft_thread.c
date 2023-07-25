/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:00:58 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/25 20:02:57 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_function(t_data *data)
{
	int				i;
	struct timeval	now;

	data->index++;
	i = data->index;
	philo_init(data, i);
	if (i % 2 == 1)
	{
		ft_thinking(data);
		usleep(data->t_eat / 2);
	}
	while (1)
	{
		ft_eating(data, i);
		ft_sleeping(data);
		ft_thinking(data);
	}
	return ;
}

int	ft_eating(t_data *data, int i)
{
	pthread_mutex_lock(&data->fork[data->info[i].first]);
	pthread_mutex_lock(&data->fork[data->info[i].second]);
	thread_print(data, FORK, i + 1);
	thread_print(data, EAT, i + 1);
	usleep(data->t_eat);
	pthread_mutex_unlock(&data->fork[data->info[i].first]);
	pthread_mutex_unlock(&data->fork[data->info[i].second]);
}

int	ft_sleeping(t_data *data)
{
	thread_print(data, SLEEP, i + 1);
	usleep(data->t_sleep);
}

int	ft_thinking(t_data *data)
{
	thread_print(data, THINK, i + 1);
}
