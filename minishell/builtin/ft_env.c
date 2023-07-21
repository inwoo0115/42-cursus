/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:49:39 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:49:40 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_main *main)
{
	t_envp	*curr;

	if (main->curr->cmd[1])
	{
		main->status = 2;
		ft_error1(ENV_ERROR);
		return ;
	}
	curr = main->ev_lst->next;
	while (curr)
	{
		if (curr->value)
			print_env(curr->key, curr->value);
		curr = curr->next;
	}
	main->status = 0;
}

void	print_env(char *key, char *value)
{
	write(1, key, ft_strlen(key));
	write(1, "=", 1);
	write(1, value, ft_strlen(value));
	write(1, "\n", 1);
}
