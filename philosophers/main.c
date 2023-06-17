/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:19:26 by wonjilee          #+#    #+#             */
/*   Updated: 2023/06/17 21:47:28 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	make_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		philo_init(data, i);
		pthread_create(&(data->threads[i]), NULL, thread_function, data);
		pthread_create(&(data->monitoring[i]), NULL, ft_monitoring, data);
		i++;
	}
	while (i < data->philo_num)
	{
		pthread_join((data->threads)[i], NULL);
		pthread_join((data->monitoring)[i], NULL);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		write(2, "Not correct argument", 20);
		exit(1);
	}
	init_data(argc, argv, &data);
	make_thread(data);
	return (0);
}
