/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 06:29:45 by wonjilee          #+#    #+#             */
/*   Updated: 2023/02/28 04:41:48 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	local_sort(t_info *data, t_stack *a, t_stack *b)
{
	t_cmd	cmd;

	cmd.num[0] = 0;
	cmd.num[1] = 0;
	cmd.num[2] = 0;
	cmd.num[3] = 0;
	init_num(a, &cmd, a->front, 0);
	check_command(data, &cmd);
	if (cmd.bb_cmd < 9)
	{
		local_bbot(data, a, b, cmd);
		data->b_bot--;
	}
	else if (cmd.ab_cmd < cmd.bt_cmd && cmd.ab_cmd != NONE)
	{
		local_abot(data, a, b, cmd);
		data->a_bot--;
	}
	else if (cmd.ab_cmd >= cmd.bt_cmd && cmd.bt_cmd != NONE)
	{
		local_btop(data, a, b, cmd);
		data->b_top--;
	}
	else
	{
		local_bbot(data, a, b, cmd);
		data->b_bot--;
	}
}

void	init_num(t_stack *a, t_cmd *cmd, int temp, int num)
{
	int	i;
	int	j;

	cmd->bt_cmd = 0;
	cmd->bb_cmd = 0;
	cmd->ab_cmd = 0;
	j = 1;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			num = (a->front - i + a->size) % a->size;
			if (a->data[temp] <= a->data[num])
				cmd->num[i]++;
			i++;
		}
		temp = (a->front - j + a->size) % a->size;
		j++;
	}
}

void	check_command(t_info *data, t_cmd *cmd)
{
	if (data->b_top > 0)
		cmd->bt_cmd = bt_command(cmd, 0);
	if (data->b_top == 0)
		cmd->bt_cmd = NONE;
	if (data->b_bot > 0)
		cmd->bb_cmd = bb_command(cmd, 0);
	if (data->b_bot == 0)
		cmd->bb_cmd = NONE;
	if (data->a_bot > 0)
		cmd->ab_cmd = ab_command(cmd, 0);
	if (data->a_bot == 0)
		cmd->ab_cmd = NONE;
}
