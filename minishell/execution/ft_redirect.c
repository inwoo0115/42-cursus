/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:50:02 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:50:02 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_redirect(t_main *main)
{
	if (inf_redirect(main) == -1 || outf_redirect(main) == -1)
		return (0);
	return (1);
}

static int	inf_redirect_func(t_main *main, t_infile *curr, int fd)
{
	fd = open(curr->file, O_RDONLY);
	if (fd < 0 && access(curr->file, F_OK) == 0)
	{
		main->status = 1;
		ft_error2(PERMISSION_ERROR, curr->file);
		return (-1);
	}
	else if (fd < 0)
	{
		main->status = 1;
		ft_error2(IN_NOFILE_ERROR, curr->file);
		return (-1);
	}
	else
	{
		dup2(fd, 0);
		close(fd);
	}
	return (0);
}

int	inf_redirect(t_main *main)
{
	t_infile		*curr;
	int				fd;

	fd = 0;
	curr = main->curr->infile->next;
	while (curr)
	{
		if (curr->file)
		{
			if (inf_redirect_func(main, curr, fd) == -1)
				return (-1);
		}
		curr = curr->next;
	}
	return (0);
}

static int	outf_redirect_func(t_main *main, t_outfile *curr, int fd)
{
	if (curr->type == 0)
		fd = open(curr->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (curr->type == 1)
		fd = open(curr->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0 && access(curr->file, F_OK) == 0)
	{
		main->status = 1;
		ft_error2(PERMISSION_ERROR, curr->file);
		return (-1);
	}
	else if (fd < 0)
	{
		main->status = 1;
		ft_error2(OPEN_ERROR, curr->file);
		return (-1);
	}
	else
	{
		dup2(fd, 1);
		close(fd);
	}
	return (0);
}

int	outf_redirect(t_main *main)
{
	int				fd;
	t_outfile		*curr;

	fd = 0;
	curr = main->curr->outfile->next;
	while (curr)
	{
		if (curr->file)
		{
			if (opendir(curr->file))
			{
				ft_error2(IS_A_DIRECTORY, curr->file);
				return (-1);
			}
			if (outf_redirect_func(main, curr, fd) == -1)
				return (-1);
		}
		curr = curr->next;
	}
	return (0);
}
