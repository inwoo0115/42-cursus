/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:01:43 by wonjilee          #+#    #+#             */
/*   Updated: 2023/02/18 23:06:05 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_res(t_stack *a, t_stack *b)
{
	if (a->data)
		free(a->data);
	if (b->data)
		free(b->data);
	return (0);
}

int	check_stack(t_stack *a, t_stack *b)
{
	int	index;

	index = a->front;
	if (b->rear == -1)
		return (0);
	while (1)
	{
		if (a->data[(index - 1 + a->size) % a->size] > a->data[index])
			return (0);
		index = (index - 1 + a->size) % a->size;
		if (index == a->rear)
			break ;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	make_stack(&a, argc, argv);
	b.size = a.size;
	b.front = -1;
	b.rear = -1;
	b.data = malloc(sizeof(int) * (a.size + 1));
	if (!(b.data))
		return (free_res(&a, &b));
	get_command(&a, &b);
	if (check_stack(&a, &b) == 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (free_res(&a, &b));
}

//checker는 다 됬는데 중복여부 검사 아직 없음