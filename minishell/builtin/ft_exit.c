/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:49:50 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:49:50 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(t_main *main, int exit_status)
{
	if (main->cmd_num == 1)
		printf("exit\n");
	if (main->curr->cmd[1] == NULL)
		exit(main->status);
	else if (check_not_digit(main->curr->cmd[1]))
	{
		ft_error2(EXIT_NOT_DIGIT_ERROR, main->curr->cmd[1]);
		exit(255);
	}
	else if (main->curr->cmd[2] != NULL)
	{
		main->status = 1;
		ft_error1(EXIT_MANY_ARG_ERROR);
		return ;
	}
	else
	{
		exit_status = ft_atoll(main, main->curr->cmd[1], 1);
		exit_status %= 256;
		if (exit_status < 0)
			exit_status = 256 + exit_status;
		exit(exit_status);
	}
	exit(255);
}

int	check_not_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}
