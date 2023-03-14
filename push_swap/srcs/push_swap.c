/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:43:13 by wonjilee          #+#    #+#             */
/*   Updated: 2023/03/14 19:42:09 by wonjilee         ###   ########.fr       */
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

int	check_sort(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->front)
	{
		if (a->data[i] < a->data[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	make_stack(&a, argc, argv);
	check_arr(&a);
	b.size = a.size;
	b.front = -1;
	b.rear = -1;
	b.data = malloc(sizeof(int) * (a.size + 1));
	if (!(b.data))
	{
		ft_error(&a);
		return (0);
	}
	if (a.size == 1 || !check_sort(&a))
		return (free_res(&a, &b));
	if (a.size <= 5)
		single_sort(&a, &b, a.size);
	else if (a.size > 5)
		ft_sort(&a, &b);
	return (free_res(&a, &b));
}
