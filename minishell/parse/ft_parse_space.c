/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:48 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:49 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_space(t_main *main, t_state *stat)
{
	if (stat->space)
		return ;
	make_new_token(main, stat);
	init_state(stat);
	stat->space = 1;
}

void	put_token(t_parse *new, char *str)
{
	int	i;

	new->token = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	i = 0;
	while (str[i])
	{
		new->token[i] = str[i];
		i++;
	}
	new->token[i] = '\0';
}

void	make_new_token(t_main *main, t_state *stat)
{
	t_parse	*new;
	t_parse	*tmp;

	if (stat->type == HEREDOC)
		run_heredoc(main, stat, 0, -1);
	new = (t_parse *)malloc(sizeof(t_parse));
	new->type = stat->type;
	new->pipe = stat->pipe;
	new->next = NULL;
	put_token(new, stat->str);
	tmp = main->parse;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
