/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:57:05 by wonjilee          #+#    #+#             */
/*   Updated: 2023/02/16 22:27:12 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, int *error, int num, int temp)
{
	int	i;
	int	pm;

	pm = 1;
	i = 0;
	if (str[i] == '-')
		pm = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == 0)
		*error = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			temp = num;
			num = num * 10 + pm * (str[i] - '0');
			if ((pm == -1 && temp <= num) || (pm == 1 && temp >= num))
				*error = 0;
		}
		else
			*error = 0;
		i++;
	}
	return (num);
}

void	make_stack(t_stack *a, int argc, char *argv[])
{
	int	i;

	i = 1;
	a->size = 0;
	while (i < argc)
		a->size += num_word(argv[i++], ' ');
	a->data = malloc(sizeof(int) * (a->size + 1));
	if (!a->data)
		exit (0);
	a->rear = 0;
	a->front = a->size - 1;
	make_arr(a, argc, argv, 0);
}

void	make_arr(t_stack *a, int argc, char *argv[], int idx)
{
	char	**temp;
	int		i;
	int		j;
	int		error;

	i = 1;
	error = 1;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ', &error);
		if (!temp)
			ft_error(a);
		j = 0;
		while (temp[j])
		{
			a->data[idx++] = ft_atoi(temp[j], &error, 0, 0);
			free(temp[j++]);
		}
		free(temp);
		i++;
	}
	if (error == 0 || argc <= 1)
		ft_error(a);
}

void	ft_error(t_stack *a)
{
	write(2, "Error\n", 6);
	free(a->data);
	exit (0);
}
