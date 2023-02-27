/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_sort5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:50:41 by wonjilee          #+#    #+#             */
/*   Updated: 2023/02/28 01:15:44 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	local_bbot(t_info *data, t_stack *a, t_stack *b, t_cmd cmd)
{
	if (cmd->num[0] == 1)
		local_bbot_num0(data, a, b, cmd);
	else if (cmd->num[1] == 1)
		local_bbot_num1(data, a, b, cmd);
	else if (cmd->num[2] == 1)
		local_bbot_num2(data, a, b, cmd);
	else if (cmd->num[3] == 1)
		local_bbot_num3(data, a, b, cmd);
}

void	local_bbot_num0(t_info *data, t_stack *a, t_stack *b, t_cmd cmd)
{
	p_command(PB, a, b);
	r_command(RB, a, b);
	if (cmd.num[1] == 2)
	{
		p_command(PB, a, b);
		r_command(RB, a, b);
		p_command(PB, a, b);
		if (cmd.num[3] == 4)
		{
			r_command(RB, a, b);
			p_command(PB, a, b);
		}
		else
		{
			p_command(PB, a, b);
			r_command(RB, a, b);
		}
		r_command(RB, a, b);
	}
	else if (cmd.num[2] == 2)
	{
		p_command(PB, a, b);
		p_command(PB, a, b);
		r_command(RB, a, b);
		if (cmd.num[3] == 4)
		{
			r_command(RB, a, b);
			p_command(PB, a, b);
		}
		else
		{
			p_command(PB, a, b);
			r_command(RB, a, b);
		}
		r_command(RB, a, b);
	}
	else if (cmd.num[3] == 2)
	{
		p_command(PB, a, b);
		p_command(PB, a, b);
		p_command(PB, a, b);
		r_command(RB, a, b);
		if (cmd.num[1] == 3)
			s_command(SB, a, b);
		r_command(RB, a, b);
		r_command(RB, a, b);	
	}
}

void	local_bbot_num1(t_info *data, t_stack *a, t_stack *b, t_cmd cmd)
{
	p_command(PB, a, b);
	p_command(PB, a, b);
	r_command(RB, a, b);
	if (cmd.num[0] == 2)
	{
		r_command(RB, a, b);
		p_command(PB, a, b);
		if (cmd.num[2] == 3)
		{
			r_command(RB, a, b);
			p_command(PB, a, b);
		}
		else
		{
			p_command(PB, a, b);
			r_command(RB, a, b);
		}
		r_command(RB, a, b);
	}
	else if (cmd.num[2] == 2)
	{
		p_command(PB, a, b);
		r_command(RB, a, b);
		if (cmd.num[0] == 3)
		{
			r_command(RB, a, b);
			p_command(PB, a, b);
		}
		else
		{
			p_command(PB, a, b);
			r_command(RB, a, b);
		}
		r_command(RB, a, b);
	}
	else
	{
		p_command(PB, a, b);
		p_command(PB, a, b);
		r_command(RB, a, b);
		if (cmd.num[0] == 3)
			s_command(SB, a, b);
		r_command(RB, a, b);
		r_command(RB, a, b);
	}
}

void	local_bbot_num2(t_info *data, t_stack *a, t_stack *b, t_cmd cmd)
{
	p_command(PB, a, b);
	p_command(PB, a, b);
	p_command(PB, a, b);
	r_command(RB, a, b);
	if (cmd.num[0] > cmd.num[1])
		s_command(SB, a, b);
	if (cmd.num[3] == 2)
	{
		p_command(PB, a, b);
		r_command(RB, a, b);
		r_command(RB, a, b);
		r_command(RB, a, b);
	}
	else
	{
		r_command(RB, a, b);
		if (cmd.num[3] == 4)
		{
			r_command(RB, a, b);
			p_command(PB, a, b);
		}
		else
		{
			p_command(PB, a, b);	
			r_command(RB, a, b);
		}
		r_command(RB, a, b);
	}
}

void	local_bbot_num3(t_info *data, t_stack *a, t_stack *b, t_cmd cmd)
{
	p_command(PB, a, b);
	p_command(PB, a, b);
	if (cmd.num[0] < cmd.num[1])
		d_command(SS, a, b);
	else
		s_command(SA, a, b);
	p_command(PB, a, b);
	r_command(RB, a, b);
	if (cmd.num[2] == 2)
	{
		p_command(PB, a, b);
		r_command(RB, a, b);
		r_command(RB, a, b);
		r_command(RB, a, b);
	}
	else
	{
		r_command(RB, a, b);
		if (cmd.num[2] == 4)
		{
			r_command(RB, a, b);
			p_command(PB, a, b);
		}
		else
		{
			p_command(PB, a, b);
			r_command(RB, a, b);
		}
		r_command(RB, a, b);
	}
}
