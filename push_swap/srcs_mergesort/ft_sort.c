/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:27:30 by wonjilee          #+#    #+#             */
/*   Updated: 2023/03/20 22:38:15 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	t_info	data;
	int		tri;

	check_tri(&data, a);
	tri = data.tri;
	while (tri > 0)
	{
		if (data.left && tri == 1)
			break ;
		local_sort(&data, a, b);
		tri--;
	}
	if (data.left && a->size <= 12)
		single_sort(a, b, data.left);
	if (data.left && a->size > 12)
		small_sort(a, b, data.left);
	// p_command(PB, a, b);
	// merge_tri_init(&data, a, b);
	merge_tri(&data, a, b, 0);
	while (find_tri(&data, a) > 1)
	{
		if (data.tri == 2)
			pass_tri_2(&data, a, b, 0);
		else if (data.tri_left == 2)
			pass_tri_left2(&data, a, b, 0);
		else if (data.tri_left == 1)
			pass_tri_left1(&data, a, b, 0);
		else
			pass_tri(&data, a, b, 0);
		merge_tri(&data, a, b, 0);
	}
}

void	check_tri(t_info *data, t_stack *a)
{
	data->left = a->size % 4;
	data->tri = a->size / 4;
	if (data->left)
		data->tri++;
	data->tri_left = data->tri % 3;
	data->b_top = data->tri / 3;
	data->b_bot = data->tri / 3;
	data->a_bot = data->tri / 3;
	if (data->tri_left >= 1)
		data->a_bot++;
	if (data->tri_left >= 2)
		data->b_top++;
	data->bt_num = data->b_top * 4;
	data->bb_num = data->b_bot * 4;
	data->ab_num = a->size - data->bt_num - data->bb_num;
}

void	merge_tri(t_info *data, t_stack *a, t_stack *b, int result)
{
	result = new_max(a, b, 0, data);
	while (data->ab_num > 0 || data->bb_num > 0 || data->bt_num > 0)
	{
		if (result == ABOT && data->ab_num > 0)
		{
			r_command(RRA, a, b);
			data->ab_num--;
		}
		else if (result == BBOT && data->bb_num > 0)
		{
			r_command(RRB, a, b);
			p_command(PA, a, b);
			data->bb_num--;
		}
		else if (result == BTOP && data->bt_num > 0)
		{
			p_command(PA, a, b);
			data->bt_num--;
		}
		else if (result == RRAB && data->ab_num > 0 && data->bb_num > 0)
		{
			d_command(RRR, a, b);
			data->ab_num--;
			p_command(PA, a, b);
			data->bb_num--;
		}
		else
			break ;
		result = compare_num(a, b, a->data[a->front], data);
	}
}

int	compare_num(t_stack *a, t_stack *b, int top, t_info *data)
{
	int		temp;

	if (data->ab_num > 0 && a->data[a->rear] < top)
		temp = a->data[a->rear];
	else if (data->bt_num > 0 && b->data[b->front] < top)
		temp = b->data[b->front];
	else if (data->bb_num > 0 && b->data[b->rear] < top)
		temp = b->data[b->rear];
	else if (data->ab_num > 0 || data->bb_num > 0 || data->bt_num > 0)
		return (new_max(a, b, 0, data));
	else
		return (0);
	if (data->ab_num > 0 && temp < a->data[a->rear] && a->data[a->rear] < top)
		temp = a->data[a->rear];
	if (data->bb_num > 0 && temp < b->data[b->rear] && b->data[b->rear] < top)
		temp = b->data[b->rear];
	if (data->bt_num > 0 && temp < b->data[b->front] && b->data[b->front] < top)
		temp = b->data[b->front];
	if (temp == a->data[a->rear] && data->ab_num > 0)
		return (check_rrr(a, b, a->data[a->front], data));
	else if (temp == b->data[b->rear] && data->bb_num > 0)
		return (BBOT);
	else if (temp == b->data[b->front] && data->bt_num > 0)
		return (BTOP);
	return (0);
}

int	new_max(t_stack *a, t_stack *b, int temp, t_info *data)
{
	if (data->ab_num > 0)
		temp = a->data[a->rear];
	else if (data->bb_num > 0)
		temp = b->data[b->rear];
	else if (data->bt_num > 0)
		temp = b->data[b->front];
	if (data->ab_num > 0 && temp < a->data[a->rear])
		temp = a->data[a->rear];
	if (data->bb_num > 0 && temp < b->data[b->rear])
		temp = b->data[b->rear];
	if (data->bt_num > 0 && temp < b->data[b->front])
		temp = b->data[b->front];
	if (data->ab_num > 0 && temp == a->data[a->rear])
		return (check_rrr(a, b, b->data[b->rear] + 1, data));
	else if (data->bb_num > 0 && temp == b->data[b->rear])
		return (BBOT);
	else if (data->bt_num > 0 && temp == b->data[b->front])
		return (BTOP);
	return (0);
}

int	check_rrr(t_stack *a, t_stack *b, int top, t_info *data)
{
	int	next;

	next = (a->rear + 1 + a->size) % a->size;
	if (data->bb_num > 0 && b->data[b->rear] < top)
	{
		if (data->bt_num > 0 && b->data[b->rear] < b->data[b->front])
			return (ABOT);
		if (data->ab_num > 1 && b->data[b->rear] < a->data[next])
			return (ABOT);
		else
			return (RRAB);
	}
	return (ABOT);
}
