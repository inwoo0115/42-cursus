/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:19:26 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/09 13:49:29 by wonjilee         ###   ########.fr       */
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
