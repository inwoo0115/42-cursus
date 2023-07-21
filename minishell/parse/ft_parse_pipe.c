/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:46 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:46 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_pipe(char *line, t_main *main, int i, t_state *stat)
{
	int	j;

	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	j = i + 1;
	while (line[j] && (line[j] == ' ' || line[i] == '\t'))
		j++;
	if (line[0] == '|' || line[j] == '<' || line[j] == '>' || \
	line[j] == '|' || line[j] == '\0')
		syntax_error(main, line, i, stat);
	if (!stat->space)
	{
		make_new_token(main, stat);
		init_state(stat);
		stat->space = 1;
	}
	stat->pipe++;
}
