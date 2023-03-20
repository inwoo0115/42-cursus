/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:52:10 by wonjilee          #+#    #+#             */
/*   Updated: 2023/03/20 23:53:31 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *a)
{
	int	temp;
	int	next;

	next = a->front;
	temp = a->data[a->front];
	while (1)
	{
		next = (next - 1 + a->size) % a->size;
		if (temp < a->data[next])
			temp = a->data[next];
		if (next == a->rear)
			break ;
	}
	return (temp);
}

void	find_min_locate(t_stack *a, t_stack *b, int temp)
{
	int	index;
	int	val;
	int	count;

	count = 0;
	index = b->front;
	while (1)
	{
		count = count_b(a, b, index);
		count += count_a(a, b, index);
		if (temp > count)
		{
			temp = count;
			
		}
		if (index == b->rear)
			break ;
	}
}

void	ft_sort_greedy(t_stack *a, t_stack *b)
{
	int	max;
	int	size;

	max = find_max(a);
	while (a->data[a->rear] == a->data[a->front])
	{
		if (a->data[a->front] == max)
			r_command(RA, a, b);
		else
			p_command(PB, a, b);
	}
	while (size > 0)
	{
		find_min_locate(a, b, a->size);
	}
}
