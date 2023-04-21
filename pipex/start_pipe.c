/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:12:43 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/21 22:14:46 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	close_pipe(t_data *data, int i)
{
	if (i == 0)
	{
		close(data->fds[1][READ]);
		close(data->outf_fd);
	}
	else if (i == data->cmd_num - 1)
	{
		if (i % 2 == 0)
			close(data->fds[0][WRITE]);
		if (i % 2 == 1)
			close(data->fds[1][WRITE]);
		close(data->inf_fd);
	}
	else
	{
		close(data->inf_fd);
		close(data->outf_fd);
	}
	if (i % 2 == 0)
	{
		close(data->fds[0][WRITE]);
		close(data->fds[1][READ]);
	}
	if (i % 2 == 1)
	{
		close(data->fds[0][READ]);
		close(data->fds[1][WRITE]);
	}
}

void	set_pipe(t_data *data, int i)
{
	close_pipe(data, i);
	if (i == 0)
	{
		dup2(data->inf_fd, 0);
		dup2(data->fds[0][WRITE], 1);
	}
	else if (i == data->cmd_num - 1)
	{
		dup2(data->fds[1][WRITE], 0);
		dup2(data->outf_fd, 1);
	}
	else if (i % 2 == 0)
	{
		dup2(data->fds[1][READ], 0);
		dup2(data->fds[0][WRITE], 1);
	}
	else if (i % 2 == 1)
	{
		dup2(data->fds[0][READ], 0);
		dup2(data->fds[1][WRITE], 1);
	}
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
		pid = fork();
		if (pid == 0)
		{
			set_pipe(data, i);
			break ;
		}
		i++;
	}
	if (pid == 0)
		set_data(data, i);
	else
		close_all(data);
	while (waitpid(-1, &data->status, 0) != -1)
	{
		printf("status: %d\n", WEXITSTATUS(data->status));
	}
}

/*
fd
0	std_in
1	std_out
2	std_err
3	infile
4	outfile

fd -> child1 (fork)
0
1
2
3
4
5	pipe1[0]
6	pipe1[1]
---
dup2()

fd
0 - infile
1
2 - pipe[write]
3 - close
4 - close
5 - close
6 - close
---
parent
fd
0
1
2
3
4
5 - pipe1[0]
6 - pipe1[1]
7 - pipe2[0]
8 - pipe2[1]

---
close(pipe1[0]);
close(pipe1[1]);
pipe(pipe1);

*/