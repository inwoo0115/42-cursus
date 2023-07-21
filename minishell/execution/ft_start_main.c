/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:11 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:11 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	start_main(t_main *main)
{
	main->curr = main->cmd_head->next;
	if (g_status == 2)
		g_status = 1;
	else if (main->cmd_num >= 0)
	{
		if (main->cmd_num == 1 && check_builtin(main->curr->cmd[0]))
		{
			if (ft_redirect(main))
				run_builtin(main);
		}
		else if (main->cmd_num == 0)
			ft_redirect(main);
		else if (main->cmd_num != 0)
			run_pipe(main, 0, 0);
		dup2(main->stdin_fd, 0);
		dup2(main->stdout_fd, 1);
	}
	clear_heredoc(main);
}

void	clear_heredoc(t_main *main)
{
	t_infile	*curr;

	curr = main->heredoc->next;
	while (curr)
	{
		unlink(curr->file);
		curr = curr->next;
	}
}

void	run_builtin(t_main *main)
{
	if (!ft_strcmp(main->curr->cmd[0], "cd"))
		ft_cd(main);
	else if (!ft_strcmp(main->curr->cmd[0], "echo"))
		ft_echo(main);
	else if (!ft_strcmp(main->curr->cmd[0], "pwd"))
		ft_pwd(main);
	else if (!ft_strcmp(main->curr->cmd[0], "export"))
		ft_export(main);
	else if (!ft_strcmp(main->curr->cmd[0], "unset"))
		ft_unset(main);
	else if (!ft_strcmp(main->curr->cmd[0], "env"))
		ft_env(main);
	else if (!ft_strcmp(main->curr->cmd[0], "exit"))
		ft_exit(main, 0);
	else
		return ;
	(void)main;
}

int	check_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "echo") || \
	!ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export") || \
	!ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "env") || \
	!ft_strcmp(cmd, "exit"))
		return (1);
	else
		return (0);
}
