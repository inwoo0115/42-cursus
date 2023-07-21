/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:51:39 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:51:39 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_export(t_envp *ev_lst)
{
	t_envp	*sorted_env;

	sorted_env = ev_lst;
	while (sorted_env)
	{
		if (sorted_env->value)
		{
			write(1, "declare -x  ", 11);
			write(1, sorted_env->key, ft_strlen(sorted_env->key));
			write(1, "=\"", 2);
			write(1, sorted_env->value, ft_strlen(sorted_env->value));
			write(1, "\"\n", 2);
		}
		else
		{
			write(1, "declare -x ", 11);
			write(1, sorted_env->key, ft_strlen(sorted_env->key));
			write(1, "\n", 1);
		}
		sorted_env = sorted_env->next;
	}
}

void	sort_env(t_main *main)
{
	t_envp	*curr;
	t_envp	*sorted;
	t_envp	*n_curr;

	sorted = NULL;
	curr = main->ev_lst->next;
	while (curr)
	{
		n_curr = curr->next;
		while (n_curr)
		{
			if (ft_strcmp(curr->key, n_curr->key) > 0)
				ft_swap(curr, n_curr);
			n_curr = n_curr->next;
		}
		if (sorted == NULL)
			sorted = curr;
		curr = curr->next;
	}
	print_export(sorted);
}

void	ft_swap(t_envp *a, t_envp *b)
{
	char	*tmp_key;
	char	*tmp_value;

	tmp_key = a->key;
	tmp_value = a->value;
	a->key = b->key;
	a->value = b->value;
	b->key = tmp_key;
	b->value = tmp_value;
}

char	*get_key(char *str)
{
	int		i;
	char	*key;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	key = (char *)malloc(i + 1);
	i = 0;
	while (str[i] != '=' && str[i])
	{
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

char	*get_value(char *str, int i, int j)
{
	int		len;
	char	*value;

	len = 0;
	while (str[i] != '=' && str[i])
		i++;
	if (str[i] == '\0')
		return (NULL);
	while (str[i++])
		len++;
	value = (char *)malloc(len);
	i = 0;
	while (str[j] != '=' && str[j])
		j++;
	if (str[j] == '\0')
		return (NULL);
	j++;
	while (str[j])
		value[i++] = str[j++];
	value[i] = '\0';
	return (value);
}
