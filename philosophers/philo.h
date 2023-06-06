/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:19:55 by wonjilee          #+#    #+#             */
/*   Updated: 2023/06/06 21:52:05 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_data
{
	int				philo_num;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	sys_mutex[4];
}	t_data;

typedef struct s_philo
{
	int	philo_num;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	must_eat;
	int	first_fork;
	int	second_fork;
}	t_philo;

//main
void	init_data(int argc, char **argv, t_data *data);
void	make_thread(t_data *data);
//utils
int		ft_atoi(const char *str);

#endif