/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:14:51 by wonjilee          #+#    #+#             */
/*   Updated: 2023/02/18 21:14:58 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	command_2(t_stack *a, t_stack *b, char *str)
{
	if (str[0] == 'p' && str[1] == 'a')
		s_command(PA, a, b);
	else if (str[0] == 'p' && str[1] == 'b')
		s_command(PB, a, b);
	else if (str[0] == 's' && str[1] == 'a')
		s_command(SA, a, b);
	else if (str[0] == 's' && str[1] == 'b')
		s_command(SB, a, b);
	else if (str[0] == 'r' && str[1] == 'a')
		s_command(RA, a, b);
	else if (str[0] == 'r' && str[1] == 'b')
		s_command(RB, a, b);
	else if (str[0] == 's' && str[1] == 's')
		d_command(SS, a, b);
	else if (str[0] == 'r' && str[1] == 'r')
		d_command(RR, a, b);
	else
		return (0);
	return (1);
}

int	command_3(t_stack *a, t_stack *b, char *str)
{
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		s_command(RRA, a, b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		s_command(RRB, a, b);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		d_command(RRB, a, b);
	else
		return (0);
	return (1);
}

int	run_command(t_stack *a, t_stack *b, char *str, int len)
{
	if (len == 3)
	{
		if (str[2] != '\n')
			return (0);
		return (command_2(a, b, str));
	}
	else if (len == 4)
	{
		if (str[3] != '\n')
			return (0);
		return (command_3(a, b, str));
	}
	return (0);
}

void	get_command(t_stack *a, t_stack *b)
{
	char	*str;
	size_t	len;

	while (1)
	{
		str = get_next_line(0);
		len = ft_strlen(str);
		if (!str)
			break ;
		if ((len != 3 && len != 4) || run_command(a, b, str, len) == 0)
		{
			write(2, "Error\n", 6);
			free(a->data);
			free(b->data);
			exit (0);
		}
		free(str);
	}
}
