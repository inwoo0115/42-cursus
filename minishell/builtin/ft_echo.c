/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:49:35 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:49:36 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(t_main *main)
{
	int	i;
	int	n_option;

	i = 1;
	n_option = 1;
	while (main->curr->cmd[i] && check_n(main->curr->cmd[i]))
		i++;
	if (i == 1)
		n_option = 0;
	if (main->curr->cmd[i])
	{
		write(1, main->curr->cmd[i], ft_strlen(main->curr->cmd[i]));
		i++;
	}
	while (main->curr->cmd[i])
	{
		write(1, " ", 1);
		write(1, main->curr->cmd[i], ft_strlen(main->curr->cmd[i]));
		i++;
	}
	if (!n_option)
		write(1, "\n", 1);
	main->status = 0;
}

int	check_n(char *str)
{
	int	i;

	i = 1;
	if (str[0] == '-')
	{
		if (str[i] == 'n')
		{
			while (str[i] == 'n')
				i++;
			if (str[i] == '\0')
				return (1);
		}
	}
	return (0);
}
