/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:27:30 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/01 21:04:01 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	t_info	data;
	int		size_a;
	int		size_b;
	int		min;

	init_stack(a, b, a->size, find_pivot(a, a->size / 3, a->front));
	size_a = check_size(a, a->front);
	while (size_a > 5)
	{
		p_command(PB, a, b);
		size_a--;
	}
	single_sort(a, b, size_a);
	size_b = a->size - size_a;
	while (size_b)
	{
		find_min_cmd(a, b, &data, b->size);
		cmd_operate(a, b, &data);
		size_b--;
	}
	min = find_min_num(a, a->front, 0);
	operate_a(a, b, min);
}

void	find_min_cmd(t_stack *a, t_stack *b, t_info *data, int temp)
{
	int	index;
	int	min;
	int	count;

	index = b->front;
	while (1)
	{
		check_count_a(a, data, b->data[index], check_size(a, a->front));
		check_count_b(b, data, index, check_size(b, b->front));
		count = data->a_num + data->b_num;
		if (data->a_rotate == data->b_rotate && data->a_num <= data->b_num)
			count = count - data->a_num;
		else if (data->a_rotate == data->b_rotate && data->a_num > data->b_num)
			count = count - data->b_num;
		if (temp > count)
		{
			temp = count;
			min = index;
		}
		if (index == b->rear)
			break ;
		index = (index - 1 + b->size) % b->size;
	}
	check_count_a(a, data, b->data[min], check_size(a, a->front));
	check_count_b(b, data, min, check_size(b, b->front));
}

void	check_count_a(t_stack *a, t_info *data, int val, int size)
{
	int	curr;
	int	i;

	i = 1;
	curr = a->front;
	while (curr != a->rear)
	{
		if (find_index_a(a, val, curr))
			break ;
		i++;
		curr = (curr - 1 + a->size) % a->size;
	}
	if (i > size / 2)
	{
		i = size - i;
		data->a_rotate = DOWN;
	}
	else
		data->a_rotate = UP;
	data->a_num = i;
}

int	find_index_a(t_stack *a, int val, int curr)
{
	int	next;

	next = (curr - 1 + a->size) % a->size;
	if (val < a->data[next] && val > a->data[curr])
		return (1);
	else if (a->data[next] < a->data[curr])
	{
		if (val < a->data[next] && val < a->data[curr])
			return (1);
		if (val > a->data[next] && val > a->data[curr])
			return (1);
	}
	return (0);
}

void	check_count_b(t_stack *b, t_info *data, int index, int size)
{
	int	curr;
	int	i;

	i = 0;
	curr = b->front;
	while (curr != index)
	{
		i++;
		curr = (curr - 1 + b->size) % b->size;
	}
	if (i < size / 2)
	{
		data->b_num = i;
		data->b_rotate = UP;
	}
	else
	{
		data->b_num = size - i;
		data->b_rotate = DOWN;
	}
}
