/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:22:18 by wonjilee          #+#    #+#             */
/*   Updated: 2023/03/05 20:49:34 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ab_command(t_cmd *cmd, int num)
{
	if (cmd->num[0] == 1)
		num = ab_command1(cmd, 4);
	else if (cmd->num[1] == 1)
	{
		num = 6;
		if (cmd->num[0] == 2)
		{
			if (cmd->num[2] == 3)
				num--;
		}
		else if (cmd->num[3] == 2)
			num++;
	}
	else if (cmd->num[2] == 1)
	{
		num = 7;
		if (cmd->num[1] > cmd->num[3])
			num++;
	}
	else if (cmd->num[3] == 1)
		num = 9;
	return (num);
}

int	ab_command1(t_cmd *cmd, int num)
{
	if (cmd->num[1] == 2)
	{
		if (cmd->num[3] == 3)
			num++;
	}
	else if (cmd->num[2] == 2)
	{
		num++;
		if (cmd->num[1] == 4)
			num++;
	}
	else if (cmd->num[3] == 2)
		num = num + 3;
	return (num);
}

int	bb_command(t_cmd *cmd, int num)
{
	num = 8;

	if (cmd->num[2] == 1)
	{
		if (cmd->num[0] < cmd->num[1])
			num++;
	}
	else if (cmd->num[3] == 1)
	{
		num++;
		if (cmd->num[0] == 4 && cmd->num[1] == 3)
			num--;
	}
	return (num);
}

int	bt_command(t_cmd *cmd, int num)
{
	num = ab_command(cmd, 0);
	if (cmd->num[1] == 1)
	{
		if (cmd->num[0] == 2 && cmd->num[2] == 4)
			num = 5;
		else if (cmd->num[0] == 4 && cmd->num[2] == 2)
			num = 7;
		else if (cmd->num[0] == 3 && cmd->num[2] == 4)
			num = 6;
	}
	else if (cmd->num[0] == 2 && cmd->num[2] == 1)
		num = 6;

	return (num);
}
