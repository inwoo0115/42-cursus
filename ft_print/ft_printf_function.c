/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:01:40 by wonjilee          #+#    #+#             */
/*   Updated: 2022/12/05 21:30:54 by wonjilee         ###   ########.fr       */
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

void	ft_lstclear(t_list **lst, void (*del)(void *))
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
		return ;
	new_convert->index = 0;
	new_convert->start = 0;
	new_convert->end = 0;
	new_convert->width = 0;
	new_convert->precision = 0;
	new_convert->u_width = 0;
	new_convert->u_zero = 0;
	new_convert->u_precision = 0;
	new_convert->u_alt = 0;
	new_convert->u_blank = 0;
	new_convert->u_plus = 0;

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
	return(add_convert(converts, new_convert));
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
	int	result;

	result = -1;
	if (text->index == PLAIN)
		result = print_plain(text);
	else if (text->index == CHAR)
		result = print_char(text, va_arg(ap, int));
	else if (text->index == STR)
		result = print_str(text, va_arg(ap, char *));
	else if (text->index == PTR)
		result = print_ptr(text, va_arg(ap, void *));
	else if (text->index == SDEC)
		result = print_sdec(text, va_arg(ap, int));
	else if (text->index == UDEC)
		result = print_udec(text, va_arg(ap, int));
	else if (text->index == LHEX)
		result = print_lhex(text, va_arg(ap, int));
	else if (text->index == UHEX)
		result = print_uhex(text, va_arg(ap, int));
	else if (text->index == PCENT)
		result = print_pcent(text);
	return (result);
}