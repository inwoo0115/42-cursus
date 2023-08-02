/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:11:08 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/02 15:57:38 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_print(t_data *data, int action, int philo)
{
	int	time;

	pthread_mutex_lock(&data->sys[PRINT]);
	time = get_time() - data->t_start;
	if (!data->death)
	{
		if (action == EAT)
			printf("%d %d is eating\n", time, philo);
		else if (action == SLEEP)
			printf("%d %d is sleeping\n", time, philo);
		else if (action == THINK)
			printf("%d %d is thinking\n", time, philo);
		else if (action == FORK)
			printf("%d %d has taken fork\n", time, philo);
		else if (action == DIE)
		{
			printf("%d %d died\n", time, philo);
			data->death = 1;
		}
	}
	pthread_mutex_unlock(&data->sys[PRINT]);
}
