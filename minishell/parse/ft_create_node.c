/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:14 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:14 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	create_infile(t_main *main, char *token, int type)
{
	t_infile	*new;
	t_infile	*curr;

	new = (t_infile *)malloc(sizeof(t_infile));
	if (type == HEREDOC)
		new->is_heredoc = 1;
	else if (type == INFILE)
		new->is_heredoc = 0;
	new->file = token;
	new->next = NULL;
	curr = main->curr->infile;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void	create_outfile(t_main *main, char *token, int type)
{
	t_outfile	*new;
	t_outfile	*curr;

	new = (t_outfile *)malloc(sizeof(t_outfile));
	if (type == OUTFILE)
		new->type = 0;
	else if (type == OUTAP)
		new->type = 1;
	new->file = token;
	new->next = NULL;
	curr = main->curr->outfile;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void	create_heredoc(t_main *main, char *file)
{
	t_infile	*new;
	t_infile	*tmp;

	new = (t_infile *)malloc(sizeof(t_infile));
	new->is_heredoc = 1;
	new->file = file;
	new->next = NULL;
	tmp = main->heredoc;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
