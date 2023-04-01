/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:29:23 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/01 20:34:19 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	free_res(t_stack *a, t_stack *b)
{
	if (a->data)
		free(a->data);
	if (b->data)
		free(b->data);
	return (0);
}

int	check_sort(t_stack *a, t_stack *b, int i)
{
	int	next;

	while (i != a->rear)
	{
		next = (i - 1 + a->size) % a->size;
		if (a->data[i] > a->data[next])
			return (KO);
		i = next;
	}
	if (b->front != -1 || b->rear != -1)
		return (KO);
	return (OK);
}

void	print_result(int result)
{
	if (result == OK)
		write(1, "OK\n", 3);
	if (result == KO)
		write(1, "KO\n", 3);
}

void	get_command(t_stack *a, t_stack *b)
{
	char	*str;
	int		error;

	error = 1;
	str = get_next_line(&error);
	while (str)
	{
		cmd_operate(command_check(str), a, b);
		free(str);
		str = get_next_line(&error);
	}
	free(str);
	if (error == 0)
	{
		free(b->data);
		ft_error(a);
	}
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
	get_command(&a, &b);
	print_result(check_sort(&a, &b, a.front));
	return (free_res(&a, &b));
}
