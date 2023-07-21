/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:52:28 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:52:29 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_status(t_main *main, int status)
{
	main->status = status;
	if (g_status == 1)
	{
		main->status = 1;
		g_status = 0;
	}
}

int	init_argu(int argc, char **argv)
{
	g_status = 0;
	if (argc > 1 || argv[1])
	{
		printf("Wrong arugment\n");
		exit(0);
	}
	return (0);
}

int	cmd_loop(char *home, int status, t_envp *ev_lst, char *line)
{
	t_main	*main;
	int		result;

	main = (t_main *)malloc(sizeof(t_main));
	main->home = home;
	main->ev_lst = ev_lst;
	change_status(main, status);
	init_main(main, line);
	add_history(line);
	start_main(main);
	result = main->status;
	free_main(main);
	return (result);
}

void	free_main(t_main *main)
{
	free_cmd(main->cmd_head->next);
	free_heredoc(main->heredoc->next);
	free_parse(main->parse->next);
	free(main->parse);
	free(main->cmd_head);
	free(main->heredoc);
	free(main);
}

int	main(int argc, char **argv, char **environ)
{
	char			*line;
	char			*home;
	t_envp			*ev_lst;
	int				status;

	set_signal();
	status = init_argu(argc, argv);
	ev_lst = parse_envp(environ, 0);
	home = save_home(ev_lst);
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			exit_line();
		if (line[0])
			status = cmd_loop(home, status, ev_lst, line);
		free(line);
	}
	return (status);
}
