/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:54:36 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/25 19:28:37 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_monitoring(t_data *data)
{
	int	i;

	i = data->index;
	while (data->death == 0 && (data->info[i]).eat_time != data->t_eat)
	{
		if ((data->info[i]).eat_time != data->t_eat && get_time() \
		- (data->info[i]).last_eat > data->t_die)
		{
			pthread_mutex_lock(&(data->sys[EAT]));
			data->death = 1;
			thread_print(data, DIE, i + 1);
			pthread_mutex_unlock(&(data->sys[EAT]));
		}
		usleep(100);
	}
	return ;
}
