/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:27:30 by wonjilee          #+#    #+#             */
/*   Updated: 2023/03/21 05:00:19 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	t_info	data;
	int		size_a;
	int		size_b;
	int		min;

	init_stack(a, b, a->size, a->data[a->size / 3]);
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
	int	cmp_1;
	int	cmp_2;
	int	i;

	i = 1;
	curr = a->front;
	while (curr != a->rear)
	{
		cmp_1 = val - a->data[curr];
		cmp_2 = val - a->data[(curr - 1 + a->size) % a->size];
		if (((cmp_1 * cmp_2) > 0 && cmp_1 < cmp_2) || (cmp_1 > 0 && cmp_2 < 0))
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

int	check_size(t_stack *a, int i)
{
	int	size;

	size = 1;
	while (i != a->rear)
	{
		size++;
		i = (i - 1 + a->size) % a->size;
	}
	return (size);
}
