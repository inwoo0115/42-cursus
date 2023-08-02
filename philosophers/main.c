/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:19:26 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/02 19:22:40 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data			data;

	if (argc < 5 || argc > 6)
	{
		write(2, "Not correct argument", 20);
		exit(1);
	}
	init_data(argc, argv, &data, -1);
	make_thread(&data, 0);
	free_all(&data);
	return (0);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	free(data->index);
	free(data->info);
	free(data->threads);
	while (i < data->philo_num)
		pthread_mutex_destroy(&(data->fork)[i++]);
	i = 0;
	while (i < 4)
		pthread_mutex_destroy(&(data->sys)[i++]);
	free(data->fork);
}
