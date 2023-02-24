/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_use.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:12:31 by wonjilee          #+#    #+#             */
/*   Updated: 2023/02/18 21:19:25 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_command(int order, t_stack *a, t_stack *b)
{
	if (order == SA)
		swap(a);
	else if (order == SB)
		swap(b);
	else if (order == PA)
		push(b, a);
	else if (order == PB)
		push(a, b);
	else if (order == RA)
		rotate(a);
	else if (order == RB)
		rotate(b);
	else if (order == RRA)
		re_rotate(a);
	else if (order == RRB)
		re_rotate(b);
}

void	d_command(int order, t_stack *a, t_stack *b)
{
	if (order == SS)
	{
		swap(a);
		swap(b);
	}
	else if (order == RR)
	{
		rotate(a);
		rotate(b);
	}
	else if (order == RRR)
	{
		re_rotate(a);
		re_rotate(b);
	}
}
