/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:12:31 by wonjilee          #+#    #+#             */
/*   Updated: 2023/03/03 17:38:00 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_command(int order, t_stack *a, t_stack *b)
{
	if (order == PA)
	{
		push(b, a);
		write(1, "pa\n", 3);
	}
	else if (order == PB)
	{
		push(a, b);
		write(1, "pb\n", 3);
	}
}

void	s_command(int order, t_stack *a, t_stack *b)
{
	if (order == SA)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	else if (order == SB)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
}

void	r_command(int order, t_stack *a, t_stack *b)
{
	if (order == RA)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if (order == RB)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	else if (order == RRA)
	{
		re_rotate(a);
		write(1, "rra\n", 4);
	}
	else if (order == RRB)
	{
		re_rotate(b);
		write(1, "rrb\n", 4);
	}
}

void	d_command(int order, t_stack *a, t_stack *b)
{
	if (order == SS)
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
	}
	else if (order == RR)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
	else if (order == RRR)
	{
		re_rotate(a);
		re_rotate(b);
		write(1, "rrr\n", 4);
	}
}
