/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_print_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:12:31 by wonjilee          #+#    #+#             */
/*   Updated: 2023/03/25 23:46:35 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	command_check(char	*str)
{
	if (str[0] == 'p' && str[1] == 'a')
		return (PA);
	else if (str[0] == 'p' && str[1] == 'b')
		return (PB);
	else if (str[0] == 's' && str[1] == 'a')
		return (SA);
	else if (str[0] == 's' && str[1] == 'b')
		return (SB);
	else if (str[0] == 'r' && str[1] == 'a')
		return (RA);
	else if (str[0] == 'r' && str[1] == 'b')
		return (RB);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		return (RRA);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		return (RRB);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		return (RRR);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\n')
		return (RR);
	else if (str[0] == 's' && str[1] == 's' && str[2] == '\n')
		return (SS);
	return (-1);
}

void	cmd_operate(int order, t_stack *a, t_stack *b)
{
	if (order == PA)
		push(b, a);
	else if (order == PB)
		push(a, b);
	else if (order == SA)
		swap(a);
	else if (order == SB)
		swap(b);
	else if (order == RA)
		rotate(a);
	else if (order == RB)
		rotate(b);
	else if (order == RRA)
		re_rotate(a);
	else if (order == RRB)
		re_rotate(b);
	else
		d_command(order, a, b);
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
	else
	{
		free(b->data);
		ft_error(a);
	}
}
