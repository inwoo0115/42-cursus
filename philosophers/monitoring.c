/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:54:36 by wonjilee          #+#    #+#             */
/*   Updated: 2023/06/17 20:52:37 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_monitoring(void *input)
{
	t_data	*data;
	int		num;

	data = input;
	num = data->index;
	while (data->death == 0 && (data->info[num]).eat_time != data->t_eat)
	{
		if ((data->info[num]).eat_time != data->t_eat && get_time() \
		- (data->info[num]).last_eat > data->t_die)
		{
			pthread_mutex_lock(&(data->sys_mutex[0]));
			data->death = 1;
//print die
			pthread_mutex_unlock(&(data->sys_mutex[0]));
		}
		usleep(100);
	}
	return ;
}
