/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:18:33 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/05 20:01:03 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	temp;

	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i])
	{
		temp = num;
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + (str[i++] - '0');
		else
			ft_error();
		if (temp > num)
			ft_error();
	}
	return (num);
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

int	eating_time(t_data *data, int i)
{
	pthread_mutex_lock(&(data->sys[EAT]));
	data->info[i - 1].last_eat = get_time();
	pthread_mutex_unlock(&(data->sys[EAT]));
	thread_print(data, EATING, i);
	while (get_time() - data->info[i - 1].last_eat < (size_t)data->t_eat)
	{
		if (!check_death(data))
			return (0);
		usleep(100);
	}
	pthread_mutex_lock(&(data->sys[EAT]));
	data->info[i - 1].eat_time++;
	pthread_mutex_unlock(&(data->sys[EAT]));
	return (1);
}
