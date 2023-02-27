/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:11:55 by wonjilee          #+#    #+#             */
/*   Updated: 2023/02/28 04:50:49 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *a, t_stack *b, int size)
{
	int	next;
	int	last;

	next = (a->front - 1 + a->size) % a->size;
	last = (next - 1 + a->size) % a->size;
	if (size == 2)
	{
		if (a->data[a->front] > a->data[next])
			s_command(SA, a, b);
	}
	else if (size == 3)
		small_sort_size3(a, b, next, last);
}

void	small_sort_size3(t_stack *a, t_stack *b, int next, int last)
{
	if (a->data[a->front] < a->data[last] && a->data[next] < a->data[last])
	{
		if (a->data[a->front] > a->data[next])
			s_command(SA, a, b);
	}
	else if (a->data[a->front] > a->data[last] && a->data[next] > a->data[last])
	{
		if (a->data[a->front] > a->data[next])
			s_command(SA, a, b);
		p_command(PB, a, b);
		p_command(PB, a, b);
		r_command(RA, a, b);
		p_command(PA, a, b);
		p_command(PA, a, b);
		r_command(RRA, a, b);
	}
	else
	{
		if (a->data[a->front] > a->data[next])
			s_command(SA, a, b);
		p_command(PB, a, b);
		s_command(SA, a, b);
		p_command(PA, a, b);
	}
}
