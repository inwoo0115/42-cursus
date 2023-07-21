/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_envp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:35 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:35 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_envp	*parse_envp(char **env_input, int i)
{
	char	**env;
	t_envp	*curr;
	t_envp	*ev_lst;

	ev_lst = (t_envp *)malloc(sizeof(t_envp));
	ev_lst->next = NULL;
	curr = ev_lst;
	while (env_input[i])
	{
		env = ft_split(env_input[i], '=');
		curr->next = create_env(env, i);
		curr = curr->next;
		i++;
	}
	return (ev_lst);
}

t_envp	*create_env(char **env, int i)
{
	t_envp	*new;
	int		j;

	new = (t_envp *)malloc(sizeof(t_envp));
	new->key = ft_strdup(env[0]);
	new->value = ft_strdup(env[1]);
	new->idx = i;
	new->next = NULL;
	j = 0;
	while (env[j])
		free(env[j++]);
	free(env);
	return (new);
}
