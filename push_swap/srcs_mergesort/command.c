/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:18:44 by wonjilee          #+#    #+#             */
/*   Updated: 2023/03/03 21:41:03 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	if (from->rear == -1)
		return ;
	to->front = (to->front + 1 + to->size) % to->size;
	to->data[to->front] = from->data[from->front];
	if (to->rear == -1)
		to->rear = to->front;
	if (from->front == from->rear)
	{
		from->front = -1;
		from->rear = -1;
	}
	else
		from->front = (from->front - 1 + from->size) % from->size;
}

void	swap(t_stack *stack)
{
	int	temp;
	int	prev;

	if (stack->front == stack->rear)
		return ;
	prev = (stack->front - 1 + stack->size) % stack->size;
	temp = stack->data[stack->front];
	stack->data[stack->front] = stack->data[prev];
	stack->data[prev] = temp;
}

void	rotate(t_stack *stack)
{
	if (stack->front == stack->rear)
		return ;
	stack->rear = (stack->rear - 1 + stack->size) % stack->size;
	stack->data[stack->rear] = stack->data[stack->front];
	stack->front = (stack->front - 1 + stack->size) % stack->size;
}

void	re_rotate(t_stack *stack)
{
	if (stack->front == stack->rear)
		return ;
	stack->front = (stack->front + 1 + stack->size) % stack->size;
	stack->data[stack->front] = stack->data[stack->rear];
	stack->rear = (stack->rear + 1 + stack->size) % stack->size;
}
