/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_exec_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:52:01 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:52:01 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_ab_path(char	*cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	**change_lst_env(t_main *main, t_envp *curr)
{
	int		len;
	int		i;
	char	**env;

	len = 0;
	i = 0;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	env = (char **)malloc(sizeof(char *) * (len + 1));
	curr = main->ev_lst->next;
	while (curr)
	{
		env[i] = ft_strjoin3(curr->key, "=", curr->value);
		curr = curr->next;
		i++;
	}
	env[i] = NULL;
	return (env);
}

void	free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
}

void	ft_exec(char *cmd, t_main *main, char **env)
{
	if (execve(cmd, main->curr->cmd, env) < 0)
	{
		ft_error1(OPEN_ERROR);
		free_env(env);
		exit(1);
	}
}
