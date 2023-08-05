/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:19:26 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/05 20:40:39 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data			data;

	if (argc < 5 || argc > 6)
		ft_error();
	init_data(argc, argv, &data, -1);
	make_thread(&data, 0);
	free_all(&data);
	destroy_all(&data);
	return (0);
}

void	free_all(t_data *data)
{

	free(data->index);
	free(data->info);
	free(data->threads);

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
