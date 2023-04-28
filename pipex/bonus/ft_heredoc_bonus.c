/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:19:55 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/28 23:52:59 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

void	ft_heredoc(t_data *data, char *limiter)
{
	char	filename[9];
	char	*str;
	int		i;

	i = 0;
	change_file(filename, i);
	while (access(filename, F_OK) == 0 && i < 100)
		change_file(filename, i++);
	if (i == 100)
		ft_error("File Not Found", data);
	data->inf_fd = open(filename, O_RDWR | O_CREAT, 0644);
	data->infile = filename;
	str = get_next_line(0);
	while (ft_strncmp(limiter, str, ft_strlen(str) - 1) != 0)
	{
		write(data->inf_fd, str, ft_strlen(str));
		free(str);
		str = get_next_line(0);
	}
	free(str);
	close(data->inf_fd);
	data->inf_fd = open(filename, O_RDONLY);
}

void	change_file(char *filename, int i)
{
	filename[0] = '/';
	filename[1] = 't';
	filename[2] = 'm';
	filename[3] = 'p';
	filename[4] = '/';
	filename[5] = '0' + i % 10;
	i /= 10;
	filename[6] = '0' + i % 10;
	i /= 10;
	filename[7] = '0' + i % 10;
	filename[8] = '\0';
}

void	init_heredoc(t_data *data, int argc, char **argv, char **envp)
{
	data->status = 0;
	data->envp = envp;
	data->cmd = argv;
	data->outfile = argv[argc - 1];
	data->cmd_num = argc - 4;
	data->not_cmd = 3;
	data->outf_fd = open(data->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (data->inf_fd == -1 || data->outf_fd == -1)
		ft_error("File Not Found", data);
}
