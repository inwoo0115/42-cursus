/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:26 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:26 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_quote(t_main *main, t_state *stat)
{
	if (stat->dq || stat->sq)
	{
		main->status = 1;
		ft_error1(QOUTE_ERROR);
		main->cmd_num = -1;
		return (1);
	}
	if (!stat->space)
		make_new_token(main, stat);
	return (0);
}

char	*parse_line(t_main *main, char *line, int *i, t_state *stat)
{
	ft_parse(main, line, *i, stat);
	if (stat->syn_error)
	{
		free(line);
		return (NULL);
	}
	if (stat->dollar)
	{
		free(line);
		line = ft_strdup(stat->newline);
		free(stat->newline);
	}
	if (stat->inred_idx || stat->outred_idx || stat->dollar)
		*i = change_idx(stat, *i);
	else
		(*i)++;
	return (line);
}

void	init_parse(t_main *main, char *line, int i)
{
	t_state	stat;

	init_state(&stat);
	stat.syn_error = 0;
	stat.space = 1;
	stat.pipe = 0;
	while (line && line[i])
	{
		line = parse_line(main, line, &i, &stat);
		if (stat.syn_error)
			return ;
	}
	if (line && check_quote(main, &stat))
	{
		free(line);
		return ;
	}
	free(line);
}

void	ft_parse(t_main *main, char *line, int i, t_state *stat)
{
	if (line[i] == '\'' && !stat->dq)
		stat->sq = !stat->sq;
	else if (line[i] == '\"' && !stat->sq)
		stat->dq = !stat->dq;
	else if (line[i] == '$' && !stat->sq && stat->type != HEREDOC)
		parse_dollar(main, line, i, stat);
	else if (line[i] == '<' && !stat->sq && !stat->dq)
		parse_in_red(line, main, i, stat);
	else if (line[i] == '>' && !stat->sq && !stat->dq)
		parse_out_red(line, main, i, stat);
	else if ((line[i] == '\t' || line[i] == ' ') && !stat->sq && !stat->dq)
		parse_space(main, stat);
	else if (line[i] == '|' && !stat->sq && !stat->dq)
		parse_pipe(line, main, i, stat);
	else
		parse_letter(line, i, stat);
	if (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '|' \
		&& !stat->sq && !stat->dq && !stat->dollar_space)
		stat->space = 0;
	if (line[i] == '\'' && stat->type == HEREDOC)
		stat->sq_heredoc = 1;
}

void	init_state(t_state *stat)
{
	stat->type = 0;
	stat->sq = 0;
	stat->dq = 0;
	stat->sq_heredoc = 0;
	stat->inred_idx = 0;
	stat->outred_idx = 0;
	stat->dollar = 0;
	stat->space = 0;
	stat->index = 0;
	stat->dollar_space = 0;
	stat->newline = NULL;
	stat->str[0] = '\0';
}
