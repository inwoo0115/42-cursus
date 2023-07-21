/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:51:43 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:51:44 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_infile(t_infile *infile)
{
	t_infile	*tmp;

	while (infile)
	{
		tmp = infile->next;
		free(infile);
		infile = tmp;
	}
}

void	free_outfile(t_outfile *outfile)
{
	t_outfile	*tmp;

	while (outfile)
	{
		tmp = outfile->next;
		free(outfile);
		outfile = tmp;
	}
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd->next;
		free_infile(cmd->infile);
		free_outfile(cmd->outfile);
		free_cmd_strs(cmd);
		free(cmd);
		cmd = tmp;
	}
}

void	free_parse(t_parse *parse)
{
	t_parse	*tmp;

	while (parse)
	{
		tmp = parse->next;
		if (parse->token)
			free(parse->token);
		free(parse);
		parse = tmp;
	}
}

void	free_heredoc(t_infile *heredoc)
{
	t_infile	*tmp;

	while (heredoc)
	{
		tmp = heredoc->next;
		if (heredoc->file)
			free(heredoc->file);
		free(heredoc);
		heredoc = tmp;
	}
}
