/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_operate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:27:30 by wonjilee          #+#    #+#             */
/*   Updated: 2023/03/21 04:32:30 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_operate(t_stack *a, t_stack *b, t_info *data)
{
	if (data->a_rotate == UP && data->b_rotate == UP)
	{
		while (data->a_num > 0 && data->b_num > 0)
		{
			d_command(RR, a, b);
			data->a_num--;
			data->b_num--;
		}
	}
	else if (data->a_rotate == DOWN && data->b_rotate == DOWN)
	{
		while (data->a_num > 0 && data->b_num > 0)
		{
			d_command(RRR, a, b);
			data->a_num--;
			data->b_num--;
		}
	}
	operate_ab(a, b, data);
}

void	operate_ab(t_stack *a, t_stack *b, t_info *data)
{
	while (data->a_num > 0)
	{
		if (data->a_rotate == UP)
			r_command(RA, a, b);
		else if (data->a_rotate == DOWN)
			r_command(RRA, a, b);
		data->a_num--;
	}
	while (data->b_num > 0)
	{
		if (data->b_rotate == UP)
			r_command(RB, a, b);
		else if (data->b_rotate == DOWN)
			r_command(RRB, a, b);
		data->b_num--;
	}
	p_command(PA, a, b);
}

int	find_min_num(t_stack *a, int curr, int i)
{
	int	min;

	min = a->data[curr];
	while (1)
	{
		if (min > a->data[curr])
			min = a->data[curr];
		if (curr == a->rear)
			break ;
		curr = (curr - 1 + a->size) % a->size;
	}
	curr = a->front;
	while (a->data[curr] != min)
	{
		i++;
		curr = (curr - 1 + a->size) % a->size;
	}
	return (i);
}

void	operate_a(t_stack *a, t_stack *b, int min)
{
	if (min > a->size / 2)
	{
		while (a->size - min > 0)
		{
			r_command(RRA, a, b);
			min++;
		}
	}
	else
	{
		while (min > 0)
		{
			r_command(RA, a, b);
			min--;
		}
	}
}
