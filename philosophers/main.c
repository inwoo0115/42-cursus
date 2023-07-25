/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:19:26 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/25 19:57:58 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data			data;
	struct timeval	start_time;

	if (argc < 5 || argc > 6)
	{
		write(2, "Not correct argument", 20);
		exit(1);
	}
	init_data(argc, argv, &data);
	gettimeofday(&start_time, NULL);
	data.t_start = start_time.tv_usec;
	make_thread(&data, -1);
	return (0);
}
