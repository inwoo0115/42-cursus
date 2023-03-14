/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:55:09 by wonjilee          #+#    #+#             */
/*   Updated: 2023/03/14 22:33:57 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_tri(t_info *data, t_stack *a)
{
	int	num;
	int	next;
	int	prev;

	num = 1;
	prev = a->front;
	next = (a->front - 1 + a->size) % a->size;
	while (1)
	{
		if (a->data[next] < a->data[prev])
			num++;
		if (next == a->rear)
			break ;
		prev = (prev - 1 + a->size) % a->size;
		next = (next - 1 + a->size) % a->size;
	}
	data->tri = num;
	data->tri_left = num % 3;
	return (num);
}

void	pass_tri_2(t_info *data, t_stack *a, t_stack *b, int next)
{
	data->bt_num = 0;
	data->bb_num = 0;
	while (1)
	{
		next = (a->front - 1 + a->size) % a->size;
		if (a->data[a->front] > a->data[next])
		{
			p_command(PB, a, b);
			data->bt_num++;
			break ;
		}
		p_command(PB, a, b);
		data->bt_num++;
	}
	data->ab_num = a->size - data->bt_num;
}

void	pass_tri(t_info *data, t_stack *a, t_stack *b, int i)
{
	int	next;

	data->bt_num = 0;
	data->bb_num = 0;
	while (i < data->tri / 3)
	{
		next = (a->front - 1 + a->size) % a->size;
		if (a->data[a->front] > a->data[next])
			i++;
		p_command(PB, a, b);
		data->bt_num++;
	}
	i = 0;
	while (i < data->tri / 3)
	{
		next = (a->front - 1 + a->size) % a->size;
		if (a->data[a->front] > a->data[next])
			i++;
		p_command(PB, a, b);
		r_command(RB, a, b);
		data->bb_num++;
	}
	data->ab_num = a->size - data->bt_num - data->bb_num;
}

void	pass_tri_left(t_info *data, t_stack *a, t_stack *b, int i)
{
	int	next;
	int	prev;
	int	left;

	left = 0;
	prev = a->rear;
	data->bt_num = 0;
	data->bb_num = 0;
	while (i < data->tri / 3 + 1)
	{
		next = (a->front - 1 + a->size) % a->size;
		if (a->data[a->front] > a->data[next])
			i++;
		p_command(PB, a, b);
		if (i == data->tri / 3)
			left++;
		data->bt_num++;
	}
	i = 0;
	while (i < data->tri / 3 + 1)
	{
		next = (a->front - 1 + a->size) % a->size;
		if (a->data[a->front] > a->data[next])
			i++;
		p_command(PB, a, b);
		r_command(RB, a, b);
		if (i == data->tri / 3)
			left++;
		data->bb_num++;
	}
	i = 0;
	while (1)
	{
		next = (prev + 1 + a->size) % a->size;
		left++;
		if (a->data[prev] < a->data[next])
			break ;
		prev = next;
	}
	data->ab_num = a->size - data->bt_num - data->bb_num + left;
}

void	pass_tri_left1(t_info *data, t_stack *a, t_stack *b, int next)
{
	int	prev;
	int	left;

	left = 0;
	prev = a->rear;
	data->bt_num = 0;
	data->bb_num = 0;
	while (1)
	{
		next = (a->front - 1 + a->size) % a->size;
		if (a->data[a->front] > a->data[next])
		{
			p_command(PB, a, b);
			data->bt_num++;
			break ;
		}
		p_command(PB, a, b);
		data->bt_num++;
	}
	while (1)
	{
		next = (prev + 1 + a->size) % a->size;
		left++;
		if (a->data[prev] < a->data[next])
			break ;
		prev = next;
	}
	data->ab_num = left;
}
