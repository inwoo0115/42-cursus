/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:05 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:06 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_exec(t_main *main)
{
	char		**paths;
	char		*path;
	char		**env;

	env = change_lst_env(main, main->ev_lst->next);
	paths = create_path(main);
	if (paths == NULL || check_ab_path(main->curr->cmd[0]))
		access_ab_path(main, env);
	else
	{
		path = find_path(main, paths, 0, 0);
		ft_exec(path, main, env);
	}
	if (paths)
		free_env(paths);
	free_env(env);
}

char	**create_path(t_main *main)
{
	t_envp	*curr;
	char	**paths;

	curr = main->ev_lst->next;
	while (curr && ft_strcmp(curr->key, "PATH") != 0)
		curr = curr->next;
	if (curr)
		paths = ft_split(curr->value, ':');
	else
		paths = NULL;
	return (paths);
}

char	*find_path(t_main *main, char **paths, int i, int file_deny)
{
	char	*path;

	while (paths[i])
	{
		path = ft_strjoin3(paths[i], "/", main->curr->cmd[0]);
		if (check_access(path) == 0)
			return (path);
		else if (check_access(path) == PERMISSION_ERROR)
			file_deny = 1;
		free(path);
		i++;
	}
	if (file_deny == -1)
	{
		ft_error2(PERMISSION_ERROR, main->curr->cmd[0]);
		exit(1);
	}
	else
	{
		ft_error2(NO_EXIST_CMD_ERROR, main->curr->cmd[0]);
		exit(127);
	}
	return (NULL);
}

int	check_access(char *path)
{
	if (opendir(path))
		return (IS_A_DIRECTORY);
	else if (access(path, F_OK) == 0 && access(path, X_OK) == -1)
		return (PERMISSION_ERROR);
	else if (access(path, X_OK) == 0)
		return (0);
	return (NO_EXIST_CMD_ERROR);
}

void	access_ab_path(t_main *main, char **env)
{
	if (check_access(main->curr->cmd[0]))
	{
		if ((check_access(main->curr->cmd[0]) == NO_EXIST_CMD_ERROR) \
		&& check_ab_path(main->curr->cmd[0]))
			ft_error2(IN_NOFILE_ERROR, main->curr->cmd[0]);
		else
			ft_error2(check_access(main->curr->cmd[0]), main->curr->cmd[0]);
		exit (1);
	}
	ft_exec(main->curr->cmd[0], main, env);
}
