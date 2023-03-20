/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_sort3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 23:29:07 by wonjilee          #+#    #+#             */
/*   Updated: 2023/03/05 21:00:24 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	local_abot(t_stack *a, t_stack *b, t_cmd cmd)
{
	if (cmd.num[0] == 1)
		local_abot_num0(a, b, cmd);
	else if (cmd.num[1] == 1)
		local_abot_num1(a, b, cmd);
	else if (cmd.num[2] == 1)
		local_abot_num2(a, b, cmd);
	else if (cmd.num[3] == 1)
		local_abot_num3(a, b, cmd);
}

void	local_abot_num0(t_stack *a, t_stack *b, t_cmd cmd)
{
	r_command(RA, a, b);
	if (cmd.num[1] == 2)
	{
		r_command(RA, a, b);
		if (cmd.num[2] == 4)
			s_command(SA, a, b);
		r_command(RA, a, b);
		r_command(RA, a, b);
	}
	else if (cmd.num[2] == 2)
	{
		s_command(SA, a, b);
		r_command(RA, a, b);
		if (cmd.num[1] == 4)
			s_command(SA, a, b);
		r_command(RA, a, b);
		r_command(RA, a, b);
	}
	else if (cmd.num[3] == 2)
	{
		p_command(PB, a, b);
		s_command(SA, a, b);
		r_command(RA, a, b);
		if (cmd.num[2] == 3)
		{
			r_command(RA, a, b);
			p_command(PA, a, b);
		}
		else
		{
			p_command(PA, a, b);
			r_command(RA, a, b);
		}
		r_command(RA, a, b);
	}
}

void	local_abot_num1(t_stack *a, t_stack *b, t_cmd cmd)
{
	if (cmd.num[0] == 2)
	{
		s_command(SA, a, b);
		r_command(RA, a, b);
		r_command(RA, a, b);
		if (cmd.num[3] == 3)
			s_command(SA, a, b);
		r_command(RA, a, b);
		r_command(RA, a, b);
	}
	else
	{
		p_command(PB, a, b);
		r_command(RA, a, b);
		if (cmd.num[3] == 2)
			s_command(SA, a, b);
		r_command(RA, a, b);
		if (cmd.num[0] == 3)
		{
			p_command(PA, a, b);
			r_command(RA, a, b);
		}
		else
		{
			r_command(RA, a, b);
			p_command(PA, a, b);
		}
		r_command(RA, a, b);
	}
}

void	local_abot_num2(t_stack *a, t_stack *b, t_cmd cmd)
{
	p_command(PB, a, b);
	s_command(SA, a, b);
	r_command(RA, a, b);
	if (cmd.num[0] == 2)
	{
		p_command(PA, a, b);
		r_command(RA, a, b);
		if (cmd.num[3] == 3)
			s_command(SA, a, b);
		r_command(RA, a, b);
		r_command(RA, a, b);
	}
	else
	{
		if (cmd.num[3] == 2)
			s_command(SA, a, b);
		r_command(RA, a, b);
		if (cmd.num[0] == 3)
		{
			p_command(PA, a, b);
			r_command(RA, a, b);
		}
		else
		{
			r_command(RA, a, b);
			p_command(PA, a, b);
		}
		r_command(RA, a, b);
	}
}

void	local_abot_num3(t_stack *a, t_stack *b, t_cmd cmd)
{
	p_command(PB, a, b);
	p_command(PB, a, b);
	if (cmd.num[0] < cmd.num[1])
		d_command(SS, a, b);
	else
		s_command(SA, a, b);
	r_command(RA, a, b);
	if (cmd.num[2] == 2)
	{
		r_command(RA, a, b);
		p_command(PA, a, b);
		r_command(RA, a, b);
		p_command(PA, a, b);
		r_command(RA, a, b);
	}
	else
	{
		p_command(PA, a, b);
		r_command(RA, a, b);
		if (cmd.num[2] == 3)
		{
			r_command(RA, a, b);
			p_command(PA, a, b);
		}
		else if (cmd.num[2] == 4)
		{
			p_command(PA, a, b);
			r_command(RA, a, b);
		}
		r_command(RA, a, b);
	}
}
