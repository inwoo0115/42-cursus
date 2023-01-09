/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:23:10 by wonjin            #+#    #+#             */
/*   Updated: 2023/01/09 19:50:24 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_convert(t_list **converts, t_convert *new_convert)
{
	t_list	*new_locate;

	new_locate = (t_list *)malloc(sizeof(t_list));
	if (new_locate == 0)
		return (0);
	new_locate->convert = new_convert;
	ft_lstadd_back(converts, new_locate);
	return (1);
}

int	check_conversion(t_list **converts, char **locate)
{
	t_convert	*new_convert;
	char		*start;
	int			flag;

	start = *locate;
	flag = check_flags(locate);
	if (flag >= 0)
	{
		new_convert = create_convert();
		if (new_convert == 0)
			return (0);
	}
	else
		return (0);
	new_convert->index = flag;
	new_convert->start = start;
	new_convert->end = locate;
	return (add_convert(converts, new_convert));
}

int	check_format(t_list **converts, const char *format)
{
	char	*locate;
	char	*temp;

	locate = (char *)format;
	while (*locate != '\0')
	{
		if (*locate == '%')
		{
			if (!(check_conversion(converts, &locate)))
				return (-1);
			locate++;
		}
		else
		{
			temp = locate;
			while (*locate != '%' && *locate != '\0')
				locate++;
			if (add_plain(converts, temp, locate) == 0)
				return (-1);
		}
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;
	t_list	*converts;

	result = check_format(&converts, format);
	if (result < 0)
	{
		ft_lstclear(converts);
		return (result);
	}
	va_start(ap, format);
	result = start_print(converts, ap);
	va_end(ap);
	ft_lstclear(converts);
	return (result);
}
