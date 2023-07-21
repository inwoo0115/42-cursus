/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:29 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:30 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_dollar(t_main *main, char *line, int i, t_state *stat)
{
	int		key_len;
	char	*newline;
	char	*temp;

	key_len = find_key_len(line, i);
	if (key_len == 0)
	{
		parse_letter(line, i, stat);
		return ;
	}
	stat->dollar = 1;
	if (key_len == -1)
	{
		temp = ft_pitoa(main->status);
		newline = ft_midjoin(i, line, temp, key_len + 3);
		free(temp);
	}
	else
	{
		newline = change_key_value(main, line, i, key_len);
		if (ft_strlen(line) == ft_strlen(newline) + key_len + 1)
			stat->dollar_space = 1;
	}
	stat->newline = newline;
}

char	*change_key_value(t_main *main, char *line, int i, int key_len)
{
	t_envp	*curr;
	char	*newline;

	curr = main->ev_lst->next;
	while (curr)
	{
		if (!ft_strncmp(&line[i + 1], curr->key, key_len) && \
		(int)ft_strlen(curr->key) == key_len)
		{
			if (curr->value)
				newline = ft_midjoin(i, line, curr->value, key_len + 1);
			else
				newline = ft_midjoin(i, line, "", key_len);
			break ;
		}
		curr = curr->next;
	}
	if (!curr)
		newline = ft_midjoin(i, line, "", key_len);
	return (newline);
}

int	find_key_len(char *line, int i)
{
	int	len;

	len = 0;
	i++;
	while (!(line[i] == '\t' || line[i] == ' ' || line[i] == '|' \
			|| line[i] == '\'' || line[i] == '\"' || line[i] == '\0' \
			|| line[i] == '$' || line[i] == '=' || line[i] == '?'))
	{
		i++;
		len++;
	}
	if (line[i] == '?' && len == 0)
		return (-1);
	return (len);
}

char	*ft_midjoin(int i, char *line, char *value, int key_len)
{
	int		len;
	char	*newline;

	len = ft_strlen(value);
	newline = (char *)malloc((len + ft_strlen(line) - key_len + 1));
	if (line[i + 1] == '?')
		put_newline_q(newline, line, value, i);
	else
		put_newline(newline, line, value, i);
	return (newline);
}

void	put_newline(char *newline, char *line, char *value, int i)
{
	int	j;
	int	k;
	int	l;

	j = 0;
	k = 0;
	l = 0;
	while (j < i)
		newline[j++] = line[k++];
	k++;
	while (!(line[k] == '\t' || line[k] == ' ' || line[k] == '|' \
			|| line[k] == '\'' || line[k] == '\"' || line[k] == '\0' \
			|| line[k] == '$' || line[k] == '=' || line[k] == '?'))
		k++;
	while (value[l])
		newline[j++] = value[l++];
	while (line[k])
		newline[j++] = line[k++];
	newline[j] = '\0';
}
