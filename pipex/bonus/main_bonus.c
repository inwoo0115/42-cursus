/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:43:52 by wonjilee          #+#    #+#             */
/*   Updated: 2023/05/02 15:17:11 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

void	run_cmd(t_data *data, char *cmd, int i)
{
	char	**cmds;
	char	*path;

	cmds = ft_split(cmd, ' ');
	while (data->paths[i])
	{
		path = ft_strjoin(data->paths[i], cmds[0]);
		if (!path)
			ft_error(ENOMEM, data);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		i++;
	}
	i = 0;
	if (execve(path, cmds, data->envp) < 0 && execve(cmd, cmds, data->envp) < 0)
	{
		while (cmds[i])
			free(cmds[i++]);
		free(cmds);
		ft_error(127, data);
	}
	while (cmds[i])
		free(cmds[i++]);
	free(cmds);
}

void	get_path(t_data *data, char **envp, int i)
{
	char	*tmp;

	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			data->paths = ft_split(envp[i] + 5, ':');
			if (!data->paths)
				ft_error(ENOMEM, data);
		}
		i++;
	}
	i = 0;
	while (data->paths[i])
	{
		tmp = ft_strjoin(data->paths[i], "/");
		if (!tmp)
			ft_error(ENOMEM, data);
		free(data->paths[i]);
		data->paths[i] = tmp;
		i++;
	}
}

void	init_data(t_data *data, int argc, char **argv, char **envp)
{
	data->status = 0;
	data->envp = envp;
	data->cmd = argv;
	data->infile = argv[1];
	data->outfile = argv[argc - 1];
	data->cmd_num = argc - 3;
	data->not_cmd = 2;
	data->inf_fd = open(data->infile, O_RDONLY);
	data->outf_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
}

int	free_res(t_data *data)
{
	int	i;

	i = 0;
	if (data->paths)
	{
		while (data->paths[i])
			free(data->paths[i++]);
		free(data->paths);
	}
	return (0);
}

int	main(int argc, char *argv[], char **envp)
{
	t_data	data;

	if (argc < 5)
		ft_error(1, &data);
	get_path(&data, envp, 0);
	if (ft_strncmp("here_doc", argv[1], 9) == 0)
	{
		if (argc < 6)
			ft_error(1, &data);
		ft_heredoc(&data, argv[2], 0);
		init_heredoc(&data, argc, argv, envp);
	}
	else
		init_data(&data, argc, argv, envp);
	start_pipe(&data);
	free_res(&data);
	return (data.exit_status);
}
