/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:49:53 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:49:53 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_ev_lst(char *str, t_main *main)
{
	char	*key;
	char	*value;

	key = get_key(str);
	if (ft_strcmp(key, "_") == 0)
	{
		free(key);
		return ;
	}
	value = get_value(str, 0, 0);
	create_env_node(key, value, main);
	free(key);
	free(value);
}

void	create_env_node(char *key, char *value, t_main *main)
{
	t_envp	*curr;
	t_envp	*new;

	curr = main->ev_lst->next;
	while (1)
	{
		if (ft_strcmp(curr->key, key) == 0)
		{
			free(curr->value);
			curr->value = ft_strdup(value);
			return ;
		}
		if (curr->next == NULL)
			break ;
		curr = curr->next;
	}
	new = (t_envp *)malloc(sizeof(t_envp));
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	curr->next = new;
}

int	check_valid(char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (1);
	i++;
	while (str[i])
	{
		if (str[i] == '=' && flag == 0)
			flag = 1;
		else if (flag == 0 && (!ft_isalpha(str[i]) \
		&& !ft_isdigit(str[i]) && str[i] != '_'))
			return (1);
		i++;
	}
	return (0);
}

void	ft_export(t_main *main)
{
	int		i;

	i = 1;
	main->status = 0;
	if (!main->curr->cmd[1])
		sort_env(main);
	else
	{
		while (main->curr->cmd[i])
		{
			if (check_valid(main->curr->cmd[i]))
			{
				ft_error2(EXPORT_ERROR, main->curr->cmd[i]);
				main->status = 1;
			}
			else
				add_ev_lst(main->curr->cmd[i], main);
			i++;
		}
	}
}
