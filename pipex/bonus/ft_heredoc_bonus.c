/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:19:55 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/29 19:04:54 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

void	ft_heredoc(t_data *data, char *limiter, int i)
{
	char	*str;

	change_file(data->filename, i);
	while (access(data->filename, F_OK) == 0 && i < 100)
		change_file(data->filename, i++);
	if (i == 100)
		ft_error(ENOENT, data);
	data->inf_fd = open(data->filename, O_RDWR | O_CREAT, 0644);
	data->infile = data->filename;
	str = get_next_line(0);
	if (!str)
		ft_error(ENOMEM, data);
	while (ft_strncmp(limiter, str, ft_strlen(str) - 1) != 0)
	{
		write(data->inf_fd, str, ft_strlen(str));
		free(str);
		str = get_next_line(0);
		if (!str)
			ft_error(ENOMEM, data);
	}
	free(str);
	close(data->inf_fd);
	data->inf_fd = open(data->filename, O_RDONLY);
	unlink(data->filename);
}

void	change_file(char *filename, int i)
{
	filename[0] = '/';
	filename[1] = 't';
	filename[2] = 'm';
	filename[3] = 'p';
	filename[4] = '/';
	filename[7] = '0' + i % 10;
	i /= 10;
	filename[6] = '0' + i % 10;
	i /= 10;
	filename[5] = '0' + i % 10;
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
		ft_error(ENOENT, data);
}
