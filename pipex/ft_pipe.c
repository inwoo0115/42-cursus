/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:12:43 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/18 21:26:08 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	set_pipe(t_data *data)
{
}

void	start_pipe(t_data *data)
{
	pid_t	pid;
	int		i;

	i = 0;
	//사용하는 fd = i
	while (i < data->cmd_num - 1)
	{
		pid = fork();
		if (pid == 0)
			break ;
		i++;
	}
	if (pid == 0)
		set_pipe(data);
	waitpid(-1, data.status, 0);
}
