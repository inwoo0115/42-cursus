/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:27:30 by wonjilee          #+#    #+#             */
/*   Updated: 2023/02/28 01:33:03 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	t_info	data;
	int		tri;

	check_tri(&data, a);
	tri = data.tri;
	while (tri > 1)
	{
		local_sort(&data, a, b);
		tri--;
	}
	if (data.left && data.tri <= 12)
		single_sort(a, b, data.left);
	if (data.left && data.tri > 12)
		small_sort(a, b, data.left);
	merge_tri(&data, a, b, 0);
	while (find_tri(&data, a) > 1)
	{
		if (data.tri == 2)
			pass_tri_2(&data, a, b);
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
	{
		data->ab_num = data->a_bot * 4 + data->tri_left;
		data->a_bot++;
	}
	if (data->tri_left >= 2)
	{
		data->b_top++;
		data->bt_num = data->b_top * 4;
	}
	data->bb_num = data->b_bot * 4;
}

void	merge_tri(t_info *data, t_stack *a, t_stack *b, int result)
{
	result = compare_num(a, b, a->data[a->front], data);
	while (result != 0)
	{
		if (result == ABOT)
		{
			r_command(RRA, a, b);
			data->ab_num--;
		}
		else if (result == BBOT)
		{
			r_command(RRB, a, b);
			p_command(PA, a, b);
			data->bb_num--;
		}
		else if (result == BTOP)
		{
			p_command(PA, a, b);
			data->bt_num--;
		}
		result = compare_num(a, b, a->data[a->front], data);
	}
}

int	compare_num(t_stack *a, t_stack *b, int a_top, t_info *data)
{
	int		temp;

	if (data->ab_num)
		temp = a->data[a->rear];
	else if (data->bb_num)
		temp = b->data[b->rear];
	else if (data->bt_num)
		temp = b->data[b->front];
	else
		return (0);
	if (a->data[a->rear] > a_top && b->data[b->rear] > a_top && \
	b->data[b->front] > a_top)
		return (new_max(a, b, temp, data));
	if (data->ab_num && temp < a->data[a->rear] && a->data[a->rear] < a_top)
		temp = a->data[a->rear];
	if (data->bb_num && temp < b->data[b->rear] && b->data[b->rear] < a_top)
		temp = b->data[b->rear];
	if (data->bt_num && temp < b->data[b->front] && b->data[b->front] < a_top)
		temp = b->data[b->front];
	if (temp == a->data[a->rear])
		return (ABOT);
	else if (temp == b->data[b->rear])
		return (BBOT);
	else if (temp == b->data[b->front])
		return (BTOP);
}

int	new_max(t_stack *a, t_stack *b, int temp, t_info *data)
{
	if (data->ab_num && temp < a->data[a->rear])
		temp = a->data[a->rear];
	if (data->bb_num && temp < b->data[b->rear])
		temp = b->data[b->rear];
	if (data->bt_num && temp < b->data[b->front])
		temp = b->data[b->front];
	if (temp == a->data[a->rear])
		return (ABOT);
	else if (temp == b->data[b->rear])
		return (BBOT);
	else if (temp == b->data[b->front])
		return (BTOP);
}
