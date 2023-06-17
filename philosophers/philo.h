/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:19:55 by wonjilee          #+#    #+#             */
/*   Updated: 2023/06/17 21:51:39 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

enum e_system
{
	eat = 0,
	sleep,
	think,
	print,
};

typedef struct s_data
{
	int				philo_num;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	int				death;
	int				index;
	t_philo			*info;
	pthread_t		*threads;
	pthread_t		*monitoring;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	sys_mutex[4];
}	t_data;

typedef struct s_philo
{
	int				index;
	int				first_fork;
	int				second_fork;
	unsigned long	eat_time;
	unsigned long	last_eat;
}	t_philo;

//main
void	init_data(int argc, char **argv, t_data *data);
void	make_thread(t_data *data);
//utils
int		ft_atoi(const char *str);

#endif