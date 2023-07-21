/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:51:54 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:51:55 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	put_newline_q(char *newline, char *line, char *value, int i)
{
	int	j;
	int	k;
	int	l;

	j = 0;
	k = 0;
	l = 0;
	while (j < i)
		newline[j++] = line[k++];
	k = k + 2;
	while (value[l])
		newline[j++] = value[l++];
	while (line[k])
		newline[j++] = line[k++];
	newline[j] = '\0';
}

int	change_idx(t_state *stat, int i)
{
	if (stat->dollar)
		stat->dollar = 0;
	else if (stat->inred_idx)
	{
		i = stat->inred_idx;
		stat->inred_idx = 0;
	}
	else if (stat->outred_idx)
	{
		i = stat->outred_idx;
		stat->outred_idx = 0;
	}
	return (i);
}
