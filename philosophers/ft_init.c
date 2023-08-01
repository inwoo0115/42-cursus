/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:21:19 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/01 21:16:09 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(int argc, char **argv, t_data *data)
{
	data->philo_num = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	data->death = 0;
	data->index = 0;
	data->threads = (pthread_t *)malloc(sizeof(pthread_t) * data->philo_num);
	data->monitoring = (pthread_t)malloc(sizeof(pthread_t));
	data->info = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
	init_mutex(data);
}

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
	data->philo_num);
	while (i < data->philo_num)
		pthread_mutex_init(&(data->fork)[i++], NULL);
	i = 0;
	while (i < 4)
		pthread_mutex_init(&(data->sys[i++]), NULL);
}

void	philo_init(t_data *data, t_philo *info, int i)
{
	i--;
	info->index = i;
	info->first = i;
	if (i == data->philo_num - 1)
		info->second = 0;
	else
		info->second = i + 1;
	info->eat_time = 0;
	info->last_eat = get_time();
}

void	make_thread(t_data *data, int i)
{
	pthread_mutex_lock(&(data->sys[THINK]));
	while (i < data->philo_num - 1)
	{
		if (i != data->index)
		{
			i = data->index;
			pthread_create(&(data->threads[data->index]), NULL, \
			(void *)thread_function, data);
		}
	}
	pthread_mutex_unlock(&(data->sys[THINK]));
	pthread_create(&data->monitoring, NULL, (void *)ft_monitoring, data);
	i = 0;
	while (i < data->philo_num)
		pthread_join((data->threads)[i++], NULL);
	pthread_join(data->monitoring, NULL);
}
