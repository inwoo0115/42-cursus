/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:49:26 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:49:27 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*process_cd_command(t_main *main)
{
	char	*pwd;

	pwd = main->curr->cmd[1];
	main->status = 0;
	if (pwd == NULL || !ft_strcmp(pwd, "~"))
	{
		chdir_home(main);
		return (NULL);
	}
	else if (!ft_strcmp(pwd, "-"))
	{
		chdir_pre(main);
		return (NULL);
	}
	else if (chdir(pwd) == -1)
	{
		main->status = 1;
		if (!access(pwd, F_OK))
			ft_error2(NOT_A_DIRECTORY, pwd);
		else
			ft_error2(CD_NO_PATH_ERROR, pwd);
		return (NULL);
	}
	return (getcwd(NULL, 0));
}

void	chdir_pre(t_main *main)
{
	t_envp	*curr;

	curr = main->ev_lst->next;
	while (curr)
	{
		if (!ft_strcmp(curr->key, "OLDPWD"))
		{
			chdir(curr->value);
			printf("%s\n", curr->value);
			return ;
		}
		curr = curr->next;
	}
	main->status = 1;
	ft_error1(NOT_SET_OLDPWD_ERROR);
}

void	chdir_home(t_main *main)
{
	t_envp	*curr;

	curr = main->ev_lst->next;
	while (curr)
	{
		if (!ft_strcmp(curr->key, "HOME"))
		{
			chdir(curr->value);
			return ;
		}
		curr = curr->next;
	}
	if (main->home == NULL)
	{
		main->status = 1;
		ft_error1(NOT_SET_HOME_ERROR);
	}
	else
		chdir(main->home);
}

char	*save_home(t_envp *ev_lst)
{
	t_envp	*curr;

	curr = ev_lst->next;
	while (curr)
	{
		if (!ft_strcmp(curr->key, "HOME"))
			return (curr->value);
		curr = curr->next;
	}
	return (NULL);
}

void	ft_cd(t_main *main)
{
	char	*pre_path;
	char	*now_path;

	pre_path = getcwd(NULL, 0);
	if (main->curr->cmd[1] && main->curr->cmd[1][0] == '\0')
	{
		free(pre_path);
		return ;
	}
	now_path = process_cd_command(main);
	if (now_path)
	{
		create_env_node("OLDPWD", pre_path, main);
		create_env_node("PWD", now_path, main);
		free(now_path);
	}
	free(pre_path);
}
