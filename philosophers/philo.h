/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:19:55 by wonjilee          #+#    #+#             */
/*   Updated: 2023/08/01 19:55:31 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

enum e_system
{
	EAT = 0,
	SLEEP,
	THINK,
	PRINT,
	FORK,
	DIE,
};

typedef struct s_data
{
	int				philo_num;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				t_start;
	int				must_eat;
	int				death;
	int				index;
	struct s_philo	*info;
	pthread_t		*threads;
	pthread_t		monitoring;
	pthread_mutex_t	*fork;
	pthread_mutex_t	sys[4];
}	t_data;

typedef struct s_philo
{
	int				index;
	int				first;
	int				second;
	int				eat_time;
	unsigned long	last_eat;
}	t_philo;

//main
void	init_data(int argc, char **argv, t_data *data);
//init
void	init_data(int argc, char **argv, t_data *data);
void	init_mutex(t_data *data);
void	philo_init(t_data *data, t_philo *info, int i);
void	make_thread(t_data *data, int i);
//utils
int		ft_atoi(const char *str);
//monitoring
void	ft_monitoring(t_data *data);
size_t	get_time(void);
//thread
void	thread_function(t_data *input);
int		ft_eating(t_data *data, int i);
int		ft_sleeping(t_data *data, int i);
int		ft_thinking(t_data *data, int i);
//print
void	thread_print(t_data *data, int action, int philo);
#endif