/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:45:45 by wonjilee          #+#    #+#             */
/*   Updated: 2023/02/25 05:24:26 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	single_sort(t_stack *a, t_stack *b, int size)
{
	int	next;

	next = (a->front - 1 + a->size) % a->size;
	if (size == 2)
	{
		if (data->a[a->front] > data->a[next])
			s_command(SA, a, b);
	}
	else if (size == 3)
		sort_size3(a, b);
	else if (size == 4)
		sort_size4(a, b);
	else if (size == 5)
		sort_size5(a, b);
}

void	sort_size3(t_stack *a, t_stack *b)
{
	int	next;
	int	last;

	next = (a->front - 1 + a->size) % a->size;
	last = (next - 1 + a->size) % a->size;
	if (a->data[a->front] < a->data[last] && a->data[next] < a->data[last])
	{
		if (a->data[a->front] > a->data[next])
			s_command(SA, a, b);
	}
	else if (a->data[a->front] > a->data[last] && a->data[next] > a->data[last])
	{
		if (a->data[a->front] > a->data[next])
			s_command(SA, a, b);
		r_command(RRA, a, b);
	}
	else
	{
		if (a->data[a->front] > a->data[next])
			s_command(SA, a, b);
		r_command(RA, a, b);
	}
}

void	sort_size4(t_stack *a, t_stack *b)
{
	int	min;
	int	next;

	min = a->front;
	next = (a->front - 1 + a->size) % a->size;
	while (1)
	{
		if (a->data[min] > a->data[next])
			min = next;
		next = (next - 1 + a->size) % a->size;
		if (next == a->rear)
			break ;
	}
	while (min != a->front)
		r_command(RA, a, b);
	p_command(PB, a, b);
	sort_size3(a, b);
	p_command(PA, a, b);
}

void	sort_size5(t_stack *a, t_stack *b)
{
	int	min;
	int	next;

	min = a->front;
	next = (a->front - 1 + a->size) % a->size;
	while (1)
	{
		if (a->data[min] > a->data[next])
			min = next;
		next = (next - 1 + a->size) % a->size;
		if (next == a->rear)
			break ;
	}
	while (min != a->front)
		r_command(RA, a, b);
	p_command(PB, a, b);
	sort_size4(a, b);
	p_command(PA, a, b);
}
