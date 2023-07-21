/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:21:19 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/21 13:21:26 by wonjilee         ###   ########.fr       */
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
	data->threads = (pthread_t *)malloc(sizeof(pthread_t) * data->philo_num);
	data->monitoring = (pthread_t *)malloc(sizeof(pthread_t) * data->philo_num);
	data->info = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
	init_mutex(data);
}

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
	data->philo_num);
	while (i < data->philo_num)
		pthread_mutex_init(&(data->fork_mutex)[i++], NULL);
	i = 0;
	while (i < 4)
		pthread_mutex_init(&(data->sys_mutex[i++]), NULL);
}

void	philo_init(t_data *data, int i)
{
	data->index = i;
	data->info[i].index = i;
	data->info[i].first_fork = i;
	data->info[i].second_fork = i + 1;
	data->info[i].eat_time = 0;
	data->info[i].last_eat = 0;
}
