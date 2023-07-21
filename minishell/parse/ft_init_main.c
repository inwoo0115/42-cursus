/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:22 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:23 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_main(t_main *main, char *line)
{
	char	*parse_line;

	main->stdin_fd = dup(0);
	main->stdout_fd = dup(1);
	main->heredoc = (t_infile *)malloc(sizeof(t_infile));
	main->heredoc->next = NULL;
	main->heredoc->file = NULL;
	main->parse = (t_parse *)malloc(sizeof(t_parse));
	main->parse->next = NULL;
	main->parse->token = NULL;
	main->cmd_num = 0;
	parse_line = ft_strdup(line);
	init_parse(main, parse_line, 0);
	main->cmd_head = (t_cmd *)malloc(sizeof(t_cmd));
	main->cmd_head->next = NULL;
	main->cmd_head->infile = NULL;
	main->cmd_head->outfile = NULL;
	main->cmd_head->cmd = NULL;
	main->curr = main->cmd_head;
	init_cmd(main, 0, main->parse->next);
	check_cmd_num(main, main->cmd_head->next);
}

void	check_cmd_num(t_main *main, t_cmd *curr)
{
	int	i;

	i = 0;
	if (main->cmd_num == -1)
		return ;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	main->cmd_num = i;
}
