/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:12:31 by wonjilee          #+#    #+#             */
/*   Updated: 2023/02/28 07:09:39 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_command(int order, t_stack *a, t_stack *b)
{
	if (order == PA)
	{
		push(b, a);
		write(1, "pa ", 3);
	}
	else if (order == PB)
	{
		push(a, b);
		write(1, "pb ", 3);
	}
}

void	s_command(int order, t_stack *a, t_stack *b)
{
	if (order == SA)
	{
		swap(a);
		write(1, "sa ", 3);
	}
	else if (order == SB)
	{
		swap(b);
		write(1, "sb ", 3);
	}
}

void	r_command(int order, t_stack *a, t_stack *b)
{
	if (order == RA)
	{
		rotate(a);
		write(1, "ra ", 3);
	}
	else if (order == RB)
	{
		rotate(b);
		write(1, "rb ", 3);
	}
	else if (order == RRA)
	{
		re_rotate(a);
		write(1, "rra ", 4);
	}
	else if (order == RRB)
	{
		re_rotate(b);
		write(1, "rrb ", 4);
	}
}

void	d_command(int order, t_stack *a, t_stack *b)
{
	if (order == SS)
	{
		swap(a);
		swap(b);
		write(1, "ss ", 3);
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
