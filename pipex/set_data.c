/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:07:33 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/21 22:06:02 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	set_data(t_data *data, int i)
{
	run_cmd(data, data->cmd[i + 2]);
}

void	close_all(t_data *data)
{
	close(data->inf_fd);
	close(data->outf_fd);
	close(data->fds[0][READ]);
	close(data->fds[0][WRITE]);
	close(data->fds[1][READ]);
	close(data->fds[1][WRITE]);
}
