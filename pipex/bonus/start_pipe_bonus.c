/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_pipe_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:12:43 by wonjilee          #+#    #+#             */
/*   Updated: 2023/05/02 18:49:24 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

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
	if (waitpid(pid, &data->status, 0))
		data->exit_status = WEXITSTATUS(data->status);
	while (waitpid(-1, &data->status, 0) != -1 && i)
		i--;
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
