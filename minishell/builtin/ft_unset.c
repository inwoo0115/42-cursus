/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:49:58 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:49:59 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(t_main *main)
{
	int			i;
	t_envp		*curr;
	t_envp		*pre;

	i = 1;
	pre = main->ev_lst;
	curr = main->ev_lst->next;
	main->status = 0;
	while (main->curr->cmd[i])
	{
		if (check_unset(main->curr->cmd[i]))
		{
			main->status = 1;
			ft_error2(UNSET_ERROR, main->curr->cmd[i]);
		}
		else
			remove_envp(curr, pre, main->curr->cmd[i]);
		i++;
	}
}

void	remove_envp(t_envp *curr, t_envp *pre, char *cmd)
{
	while (curr)
	{
		if (!ft_strcmp(curr->key, cmd))
		{
			free(curr->key);
			free(curr->value);
			if (curr->next)
				pre->next = curr->next;
			else
				pre->next = 0;
			free(curr);
			break ;
		}
		pre = curr;
		curr = curr->next;
	}
}

int	check_unset(char *str)
{
	int	i;

	i = 1;
	if ((!ft_isalpha(str[0]) && str[0] != '_') || str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isalpha(str[i]) && str[i] != '_')
			return (1);
		i++;
	}
	return (0);
}
