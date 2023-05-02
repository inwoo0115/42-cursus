/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:07:33 by wonjilee          #+#    #+#             */
/*   Updated: 2023/05/02 15:17:39 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

void	close_all(t_data *data)
{
	close(data->inf_fd);
	close(data->outf_fd);
	close(data->fds[0][READ]);
	close(data->fds[0][WRITE]);
	close(data->fds[1][READ]);
	close(data->fds[1][WRITE]);
}

void	first_cmd(t_data *data, int i)
{
	if (data->inf_fd == -1 || data->outf_fd == -1)
		ft_error(2, data);
	close(data->fds[1][READ]);
	close(data->fds[1][WRITE]);
	close(data->outf_fd);
	close(data->fds[0][READ]);
	dup2(data->inf_fd, 0);
	dup2(data->fds[0][WRITE], 1);
	run_cmd(data, data->cmd[i + data->not_cmd], 0);
}

void	mid_cmd(t_data *data, int i)
{
	if (i % 2 == 1)
	{
		close(data->fds[1][READ]);
		close(data->fds[0][WRITE]);
		dup2(data->fds[0][READ], 0);
		dup2(data->fds[1][WRITE], 1);
	}
	else if (i % 2 == 0)
	{
		close(data->fds[0][READ]);
		close(data->fds[1][WRITE]);
		dup2(data->fds[1][READ], 0);
		dup2(data->fds[0][WRITE], 1);
	}
	close(data->inf_fd);
	close(data->outf_fd);
	run_cmd(data, data->cmd[i + data->not_cmd], 0);
}

void	last_cmd(t_data *data, int i)
{
	close(data->inf_fd);
	if (i % 2 == 1)
	{
		close(data->fds[1][READ]);
		close(data->fds[1][WRITE]);
		close(data->fds[0][WRITE]);
		dup2(data->fds[0][READ], 0);
	}
	else if (i % 2 == 0)
	{
		close(data->fds[0][READ]);
		close(data->fds[0][WRITE]);
		close(data->fds[1][WRITE]);
		dup2(data->fds[1][READ], 0);
	}
	dup2(data->outf_fd, 1);
	run_cmd(data, data->cmd[i + data->not_cmd], 0);
}
