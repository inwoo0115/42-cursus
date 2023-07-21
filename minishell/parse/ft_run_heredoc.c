/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:52 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:52 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_file(char *file, int i)
{
	file[0] = '/';
	file[1] = 't';
	file[2] = 'm';
	file[3] = 'p';
	file[4] = '/';
	file[7] = '0' + i % 10;
	i /= 10;
	file[6] = '0' + i % 10;
	i /= 10;
	file[5] = '0' + i % 10;
	file[8] = '\0';
}

char	*heredoc_parse_dollar(t_main *main, char *line, int i)
{
	int		key_len;
	char	*newline;
	char	*temp;

	key_len = find_key_len(line, i);
	if (key_len == -1)
	{
		temp = ft_pitoa(main->status);
		newline = ft_midjoin(i, line, temp, key_len + 3);
		free(temp);
	}
	else
		newline = change_key_value(main, line, i, key_len);
	free(line);
	return (newline);
}

char	*check_file(void)
{
	char	*file;
	int		i;

	file = (char *)malloc(sizeof(char) * 9);
	i = 0;
	change_file(file, i);
	while (access(file, F_OK) == 0)
		change_file(file, ++i);
	return (file);
}

void	make_heredoc_file(t_main *main, t_state *stat, int fd, int i)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			cursor();
			return ;
		}
		if (!ft_strcmp(stat->str, line))
			break ;
		i = 0;
		while (line[i])
		{
			if (line[i] == '$' && !stat->sq_heredoc && line[i + 1] != '\0' \
			&& find_key_len(line, i) != 0)
				line = heredoc_parse_dollar(main, line, i);
			else
				i++;
		}
		ft_putstr_fd_free(line, fd);
		write(fd, "\n", 1);
	}
	free(line);
}

void	run_heredoc(t_main *main, t_state *stat, int fd, int i)
{
	int		status;
	pid_t	pid;
	char	*file;

	pid = fork();
	file = check_file();
	create_heredoc(main, file);
	signal(SIGINT, SIG_IGN);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		fd = open(file, O_RDWR | O_CREAT, 0644);
		make_heredoc_file(main, stat, fd, 0);
		close(fd);
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		write(1, "\n", 1);
		g_status = 2;
	}
	set_signal();
	put_str(stat->str, file, i);
}
