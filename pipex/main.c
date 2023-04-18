/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:43:52 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/18 22:11:27 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	run_cmd(t_data *data, char *cmd)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(cmd, ' ');
	while (data->paths[i])
	{
		path = ft_strjoin(data->paths[i], cmd[0]);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		i++;
	}
	execve(path, cmd, data->envp);
}

void	get_path(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			data->paths = ft_split(envp[i] + 5, ':');
		i++;
	}
}

void	init_data(t_data *data, int argc, char **argv, char **envp)
{
	int	i;

	i = 0;
	data->fds = (int **)malloc(sizeof(int *) * (argc - 1));
	if (!data->fds)
		return ;
	while (i < argc - 1)
	{
		data->fds[i] = (int *)malloc(sizeof(int) * 2);
		if (!data->fds[i])
			return ;
		i++;
	}
	data->status = 0;
	data->envp = envp;
	data->cmd = argv;
	data->infile = argv[1];
	data->outfile = argv[argc - 1];
	data->cmd_num = argc - 1;
}

int	main(int argc, char *argv[], char **envp)
{
	t_data	data;

	get_path(&data, envp);
	init_data(&data, argc, argv, envp);
	start_pipe(&data);
	return (0);
}
