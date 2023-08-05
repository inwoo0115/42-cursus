/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:21:19 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/05 20:40:36 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	make_thread(t_data *data, int i)
{
	pthread_mutex_lock(&(data->sys[START]));
	while (i < data->philo_num)
		pthread_create(&(data->threads[i++]), NULL, \
		(void *)thread_function, data);
	pthread_mutex_unlock(&(data->sys[START]));
	pthread_create(&data->monitoring, NULL, (void *)ft_monitoring, data);
	i = 0;
	while (i < data->philo_num)
		pthread_join((data->threads)[i++], NULL);
	pthread_join(data->monitoring, NULL);
}

void	init_data(int argc, char **argv, t_data *data, int i)
{
	data->philo_num = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (data->philo_num < 1 || data->t_die < 1 \
	|| data->t_eat < 1 || data->t_sleep < 1)
		ft_error();
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	data->death = 0;
	data->index = (int *)malloc(sizeof(int) * data->philo_num);
	init_index(data);
	data->threads = (pthread_t *)malloc(sizeof(pthread_t) * data->philo_num);
	data->info = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
	data->t_start = get_time();
	while (++i < data->philo_num)
		init_philo(data, &(data->info[i]), i);
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

void	init_philo(t_data *data, t_philo *info, int i)
{
	info->index = i;
	info->first = i;
	if (i == data->philo_num - 1)
		info->second = 0;
	else
		info->second = i + 1;
	info->eat_time = 0;
	info->last_eat = data->t_start;
}
