/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:00:58 by wonjilee          #+#    #+#             */
/*   Updated: 2023/06/17 20:52:48 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_function(void *input)
{
	t_data			*data;
	int				num;
	struct timeval	now;

	data = input;
	num = data->index;
	while ()
	{
		ft_eating(data, philo);
		ft_sleeping(data, philo);
		ft_thinking(data, philo);
	}
	return ;
}

int	ft_eating(t_data *data, t_philo *philo)
{
}

int	ft_sleeping(t_data *data, t_philo *philo)
{
}

int	ft_thinking(t_data *data, t_philo *philo)
{
}
