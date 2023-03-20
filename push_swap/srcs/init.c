/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 01:01:28 by wonjilee          #+#    #+#             */
/*   Updated: 2023/03/21 05:00:18 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *a, t_stack *b, int size, int p1)
{
	int		p2;

	p2 = a->data[(a->size / 3) * 2];
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
