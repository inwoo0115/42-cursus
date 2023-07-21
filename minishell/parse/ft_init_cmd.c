/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:19 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:20 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_cmd(t_main *main, int pipe, t_parse *p_curr)
{
	char	*cmd;
	int		i;

	i = 0;
	cmd = NULL;
	make_cmd_node(main, pipe);
	while (p_curr)
	{
		if (pipe != p_curr->pipe)
		{
			pipe = p_curr->pipe;
			main->curr->cmd[i] = NULL;
			make_cmd_node(main, pipe);
			i = 0;
			cmd = NULL;
		}
		cmd = create_file_node(main, p_curr);
		if (cmd)
			main->curr->cmd[i++] = cmd;
		p_curr = p_curr->next;
	}
	main->curr->cmd[i] = NULL;
}

char	*create_file_node(t_main *main, t_parse *p_curr)
{
	char	*tmp;

	if (p_curr->type == INFILE || p_curr->type == HEREDOC)
		create_infile(main, p_curr->token, p_curr->type);
	else if (p_curr->type == OUTFILE || p_curr->type == OUTAP)
		create_outfile(main, p_curr->token, p_curr->type);
	else if (p_curr->type == CMD)
	{
		if (p_curr->token == NULL)
		{
			tmp = malloc(1);
			tmp[0] = '\0';
		}
		else
			tmp = ft_strdup(p_curr->token);
		return (tmp);
	}
	return (NULL);
}

char	**cmd_node_split(t_main *main, int pipe)
{
	int		i;
	t_parse	*curr;
	char	**temp;

	curr = main->parse->next;
	i = 0;
	while (curr)
	{
		if (curr->pipe == pipe && curr->type == CMD)
			i++;
		curr = curr->next;
	}
	temp = (char **)malloc(sizeof(char *) * (i + 1));
	return (temp);
}

void	make_cmd_node(t_main *main, int i)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	new->idx = i;
	new->cmd = cmd_node_split(main, i);
	new->infile = (t_infile *)malloc(sizeof(t_infile));
	new->infile->next = NULL;
	new->infile->file = NULL;
	new->outfile = (t_outfile *)malloc(sizeof(t_outfile));
	new->outfile->next = NULL;
	new->outfile->file = NULL;
	new->next = NULL;
	main->curr->next = new;
	main->curr = main->curr->next;
}
