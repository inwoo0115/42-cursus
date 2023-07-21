/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_in_red.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:37 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:38 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_in_red(char *line, t_main *main, int i, t_state *stat)
{
	int	index;

	if (!stat->space)
	{
		make_new_token(main, stat);
		init_state(stat);
		stat->space = 1;
	}
	index = check_infile(line, main, i, stat);
	stat->inred_idx = index;
}

int	check_infile(char *line, t_main *main, int i, t_state *stat)
{
	int		is_heredoc;

	is_heredoc = 0;
	if (line[i + 1] == '<')
	{
		is_heredoc = 1;
		i++;
	}
	i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '<' || line[i] == '>' || line[i] == '|')
		syntax_error(main, line, i, stat);
	if (line[i] == '\0')
		syntax_error_null(main, stat);
	if (is_heredoc)
		stat->type = HEREDOC;
	else
		stat->type = INFILE;
	return (i);
}
