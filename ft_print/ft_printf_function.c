/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:01:40 by wonjilee          #+#    #+#             */
/*   Updated: 2022/12/28 15:15:32 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst == 0 && new != 0)
	{
		*lst = new;
		return ;
	}
	else if (new == 0)
		return ;
	while ((*lst)->next != 0)
		*lst = (*lst)->next;
	(*lst)->next = new;
	*lst = temp;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	while (*lst != 0)
	{
		temp = (*lst)->next;
		free((*lst)->convert);
		free(*lst);
		*lst = temp;
	}
}

t_convert	*create_convert(void)
{
	t_convert	*new_convert;

	new_convert = (t_convert *)malloc(sizeof(t_convert));
	if (new_convert == 0)
		return (0);
	new_convert->index = 0;
	new_convert->start = 0;
	new_convert->end = 0;
	return (new_convert);
}

int	add_plain(t_list **converts, char *temp, char *locate)
{
	t_convert	*new_convert;
	char		*start;
	int			check;

	check = 1;
	new_convert = create_convert();
	if (new_convert == 0)
		return (0);
	start = *locate;
	new_convert->index = PLAIN;
	new_convert->start = start;
	new_convert->end = locate;
	return (add_convert(converts, new_convert));
}

int	start_print(t_list *converts, va_list ap)
{
	int			len;
	int			result;

	len = 0;
	while (converts != 0)
	{
		result = print_convert(converts->convert, ap);
		if (result < 0)
			return (result);
		len += result;
		converts = converts->next;
	}
	return (len);
}

int	print_convert(t_convert *text, va_list ap)
{
	if (text->index == PLAIN)
		return (print_plain(text));
	else if (text->index == CHAR)
		return (print_char(text, va_arg(ap, int)));
	else if (text->index == STR)
		return (print_str(text, va_arg(ap, char *)));
	else if (text->index == PTR)
		return (print_ptr(text, va_arg(ap, void *)));
	else if (text->index == DEC)
		return (print_dec(text, va_arg(ap, int)));
	else if (text->index == IDEC)
		return (print_idec(text, va_arg(ap, int)));
	else if (text->index == UDEC)
		return (print_udec(text, va_arg(ap, int)));
	else if (text->index == LHEX)
		return (print_lhex(text, va_arg(ap, int)));
	else if (text->index == UHEX)
		return (print_uhex(text, va_arg(ap, int)));
	else if (text->index == PCENT)
		return (print_pcent(text));
	return (-1);
}

int	check_flags(char **locate)
{
	locate++;
	if (*locate == 'c')
		return (CHAR);
	else if (*locate == 's')
		return (STR);
	else if (*locate == 'p')
		return (PTR);
	else if (*locate == 'd')
		return (DEC);
	else if (*locate == 'i')
		return (IDEC);
	else if (*locate == 'u')
		return (UDEC);
	else if (*locate == 'x')
		return (LHEX);
	else if (*locate == 'X')
		return (UHEX);
	else if (*locate == '%')
		return (PCENT);
	else
		return (-1);
}
