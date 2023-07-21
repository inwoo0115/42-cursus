/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_out_red.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:43 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:43 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_out_red(char *line, t_main *main, int i, t_state *stat)
{
	int	index;

	if (!stat->space)
	{
		make_new_token(main, stat);
		init_state(stat);
		stat->space = 1;
	}
	index = check_outfile(line, main, i, stat);
	stat->outred_idx = index;
}

int	check_outfile(char *line, t_main *main, int i, t_state *stat)
{
	int		is_append;

	is_append = 0;
	if (line[i + 1] == '>')
	{
		is_append = 1;
		i++;
	}
	i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '<' || line[i] == '>' || line[i] == '|')
		syntax_error(main, line, i, stat);
	if (line[i] == '\0')
		syntax_error_null(main, stat);
	if (is_append)
		stat->type = OUTAP;
	else
		stat->type = OUTFILE;
	return (i);
}
