/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:12:43 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/29 19:30:24 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	set_pipe(t_data *data, int i)
{
	if (i == 0)
		first_cmd(data, i);
	else if (i == data->cmd_num - 1)
		last_cmd(data, i);
	else
		mid_cmd(data, i);
}

void	start_pipe(t_data *data)
{
	pid_t	pid;
	int		i;

	pipe(data->fds[0]);
	pipe(data->fds[1]);
	i = 0;
	while (i < data->cmd_num)
	{
		if (i >= 2)
			re_pipe(data, i);
		pid = fork();
		if (pid == 0)
		{
			set_pipe(data, i);
			break ;
		}
		i++;
	}
	if (pid != 0)
		close_all(data);
	if (waitpid(-1, &data->status, 0) > 0)
	{
		if (WEXITSTATUS(data->status) > 0)
			ft_error(WEXITSTATUS(data->status), data);
	}
}

void	re_pipe(t_data *data, int i)
{
	if (i % 2 == 0)
	{
		close(data->fds[0][0]);
		close(data->fds[0][1]);
		pipe(data->fds[0]);
	}
	else if (i % 2 == 1)
	{
		close(data->fds[1][0]);
		close(data->fds[1][1]);
		pipe(data->fds[1]);
	}
}
