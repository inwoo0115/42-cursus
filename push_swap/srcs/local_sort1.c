/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 06:29:45 by wonjilee          #+#    #+#             */
/*   Updated: 2023/02/25 09:01:21 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	local_sort(t_info *data, t_stack *a, t_stack *b)
{
	int	num1;
	int	num2;
	int	num3;
	int	num4;

	num1 = a->front;
	num2 = (num1 - 1 + a->size) % a->size;
	num3 = (num2 - 1 + a->size) % a->size;
	num4 = (num3 - 1 + a->size) % a->size;
}

int	check_command(t_info *data, t_stack *a, t_stack *b)
{
}

int	local_abot(t_info *data, t_stack *a, t_stack *b)
int	local_bbot(t_info *data, t_stack *a, t_stack *b)
int	local_btop(t_info *data, t_stack *a, t_stack *b)

