/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:24:11 by wonjilee          #+#    #+#             */
/*   Updated: 2023/05/02 22:02:40 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	run_cmd(t_data *data, char *cmd, int i)
{
	char	**cmds;
	char	*path;
	int		pd;

	pd = 0;
	cmds = ft_split(cmd, ' ');
	while (data->paths[i])
	{
		path = ft_strjoin(data->paths[i++], cmds[0]);
		if (!path)
			ft_error(ENOMEM, data);
		if (access(path, F_OK) == 0)
			pd = 1;
		if (access(path, X_OK) == 0)
			break ;
		free(path);
	}
	if (ft_execve(data, path, cmds, cmd) == 1)
	{
		if (pd == 1 || (access(cmd, F_OK) == 0 && access(cmd, X_OK) != 0))
			ft_error(3, data);
		else if (pd == 0)
			ft_error(127, data);
	}
	free(path);
}

int	ft_execve(t_data *data, char *path, char **cmds, char *cmd)
{
	int	i;
	int	cmd_error;

	i = 0;
	cmd_error = 0;
	if (execve(path, cmds, data->envp) < 0 && execve(cmd, cmds, data->envp) < 0)
		cmd_error = 1;
	while (cmds[i])
		free(cmds[i++]);
	free(cmds);
	return (cmd_error);
}
