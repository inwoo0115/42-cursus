/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:43:52 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/28 17:06:06 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	run_cmd(t_data *data, char *cmd)
{
	char	**cmds;
	char	*path;
	int		i;

	i = 0;
	cmds = ft_split(cmd, ' ');
	while (data->paths[i])
	{
		path = ft_strjoin(data->paths[i], cmds[0]);
		if (!path)
			ft_error("Memory Error", data);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		i++;
	}
	if (execve(path, cmds, data->envp) < 0)
		ft_error("Command Not Found", data);
	i = 0;
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
				ft_error("Memory Error", data);
		}
		i++;
	}
	i = 0;
	while (data->paths[i])
	{
		tmp = data->paths[i];
		free(data->paths[i]);
		data->paths[i] = ft_strjoin(tmp, "/");
		if (!data->paths[i])
			ft_error("Memory Error", data);
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
	data->inf_fd = open(data->infile, O_RDONLY);
	data->outf_fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->inf_fd == -1 || data->outf_fd == -1)
		ft_error("File Not Found", data);
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

	if (argc != 5)
		ft_error("Wrong arguments", &data);
	get_path(&data, envp, 0);
	init_data(&data, argc, argv, envp);
	start_pipe(&data);
	return (free_res(&data));
}

//here doc 추가
