/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:20:57 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/09 13:49:26 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(void)
{
	write(2, "Not correct argument", 20);
	exit(1);
}

void	ft_error_thread(t_data *data, int i)
{
	int	index;

	index = 0;
	if (i != -1)
	{
		while (index < i)
			pthread_detach(data->threads[index++]);
	}
	destroy_all(data);
	free_all(data);
	exit(1);
}

void	free_all(t_data *data)
{
	if (data->index)
		free(data->index);
	if (data->info)
		free(data->info);
	if (data->threads)
		free(data->threads);
	if (data->fork)
		free(data->fork);
}

void	destroy_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
		pthread_mutex_destroy(&(data->fork)[i++]);
	i = 0;
	while (i < 4)
		pthread_mutex_destroy(&(data->sys)[i++]);
}
