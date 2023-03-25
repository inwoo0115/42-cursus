/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 01:01:28 by wonjilee          #+#    #+#             */
/*   Updated: 2023/03/25 21:51:27 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *a, t_stack *b, int size, int p1)
{
	int		p2;

	p2 = find_pivot(a, a->size / 3 * 2, a->front);
	while (size > 0)
	{
		if (a->data[a->front] <= p1)
		{
			if (size > 1 && a->data[(a->front - 1 + a->size) % a->size] > p2)
			{
				p_command(PB, a, b);
				d_command(RR, a, b);
				size--;
			}
			else
			{
				p_command(PB, a, b);
				r_command(RB, a, b);
			}
		}
		else if (a->data[a->front] < p2)
			p_command(PB, a, b);
		else if (a->data[a->front] >= p2)
			r_command(RA, a, b);
		size--;
	}
}

int	find_pivot(t_stack *a, int index, int i)
{
	int	j;
	int	num;

	while (i != a->rear)
	{
		num = 0;
		j = a->front;
		while (j != a->rear)
		{
			if (a->data[i] > a->data[j])
				num++;
			j = (j - 1 + a->size) % a->size;
		}
		if (num == index)
			return (a->data[i]);
		i = (i - 1 + a->size) % a->size;
	}
	return (0);
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
