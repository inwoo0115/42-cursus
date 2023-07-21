/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:08 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:09 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_status(t_main *main, int status, int i, int input_fd)
{
	if (WTERMSIG(status) == 2)
	{
		printf("^C\n");
		main->status = 130;
	}
	else if (WTERMSIG(status) == 3)
	{
		main->status = 131;
		printf("^\\Quit: 3\n");
	}
	while (waitpid(-1, &status, 0) != -1 && i)
		i--;
	close(input_fd);
	set_signal();
}

void	child_process(t_main *main, int fds[], int input_fd, int i)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	set_pipe(main, fds, input_fd, i);
}

void	run_pipe(t_main *main, int i, int status)
{
	int		fds[2];
	int		input_fd;
	pid_t	pid;

	input_fd = dup(0);
	while (i < main->cmd_num)
	{
		pipe(fds);
		pid = fork();
		if (pid == 0)
		{
			child_process(main, fds, input_fd, i);
			break ;
		}
		else if (pid > 0)
		{
			input_fd = re_pipe(fds, input_fd);
			signal(SIGINT, SIG_IGN);
		}
		main->curr = main->curr->next;
		i++;
	}
	if (waitpid(pid, &status, 0))
		main->status = WEXITSTATUS(status);
	check_status(main, status, i, input_fd);
}

void	set_pipe(t_main *main, int *fds, int input_fd, int index)
{
	if (index != main->cmd_num - 1)
		dup2(fds[1], 1);
	dup2(input_fd, 0);
	close(input_fd);
	close(fds[1]);
	close(fds[0]);
	if (ft_redirect(main))
	{
		if (check_builtin(main->curr->cmd[0]))
		{
			run_builtin(main);
			exit (main->status);
		}
		else if (main->curr->cmd[0])
			run_exec(main);
	}
	exit (main->status);
}

int	re_pipe(int *fds, int input_fd)
{
	close(fds[1]);
	close(input_fd);
	input_fd = dup(fds[0]);
	close(fds[0]);
	return (input_fd);
}
