/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:55:09 by wonjilee          #+#    #+#             */
/*   Updated: 2023/02/25 05:24:25 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_tri(t_info *data, t_stack *a)
{
	int	num;
	int	next;
	int	prev;

	num = 0;
	prev = a->front;
	while (1)
	{
		next = (prev - 1 + a->size) % a->size;
		if (a->data[next] < a->data[prev])
			num++;
		if (next == a->rear)
			break ;
		prev = next;
	}
	data->tri = num;
	data->tri_left = num % 3;
}

void	pass_tri_2(t_info *data, t_stack *a, t_stack *b)
{
	while (a->data[a->front] < b->data[b->front])
	{
		p_command(PB, a, b);
		data->bt_num++;
	}
	data->ab_num = a->size - data->bt_num;
}

void	pass_tri(t_info *data, t_stack *a, t_stack *b, int i)
{
	while (i < data->tri / 3)
	{
		p_command(PB, a, b);
		data->bt_num++;
		if (a->data[a->front] < b->data[b->front])
			i++;
	}
	i = 0;
	while (i < data->tri / 3)
	{
		p_command(PB, a, b);
		r_command(RB, a, b);
		data->bb_num++;
		if (a->data[a->front] < b->data[b->rear])
			i++;
	}
	data->ab_num = a->size - data->bt_num - data->bb_num;
}
