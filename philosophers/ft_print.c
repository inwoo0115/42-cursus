/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:11:08 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/25 20:02:53 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_print(t_data *data, int action, int philo)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	now.tv_usec = now.tv_usec - data->t_start;
	pthread_mutex_lock(&data->sys[PRINT]);
	if (action == EAT)
		printf("%d %d is eating", now.tv_usec, philo);
	else if (action == SLEEP)
		printf("%d %d is sleeping", now.tv_usec, philo);
	else if (action == THINK)
		printf("%d %d is thinking", now.tv_usec, philo);
	else if (action == FORK)
		printf("%d %d has taken fork", now.tv_usec, philo);
	else if (action == DIE)
		printf("%d %d died", now.tv_usec, philo);
	pthread_mutex_unlock(&data->sys[PRINT]);
}
