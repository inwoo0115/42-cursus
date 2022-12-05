/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjin <wonjilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:23:10 by wonjin            #+#    #+#             */
/*   Updated: 2022/12/05 15:45:07 by wonjin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_conversion(t_list **converts, t_convert *new_convert, char *start, char *locate)
{
	t_list	*new_locate;

	new_locate = (t_list *)malloc(sizeof(t_list));
	if (new_locate == 0);
		return (0);
	

}

int	check_conversion(t_list **converts, char **locate)
{
	t_convert	*new_convert;
	char		*start;
	int			check;

	check = 0;
	new_convert = (t_convert *)malloc(sizeof(t_convert));
	if (new_convert == 0)
		return (0);
	start = *locate;
	//형식 해석 함수 추가 예정
	if (check == 0)
	{
		free(new_convert);
		return (0);
	}
	add_conversion(converts, new_convert, start, locate);
	return (check);
}

int	check_format(t_list **converts, const char *format)
{
	char	*locate;

	locate = (char *)format;
	while (*locate != '\0')
	{
		if (*locate == '%')
		{
			if 

		}

	}

}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;

	result = 0;
	va_start(ap, format);
	result = check_format(ap, (char *)format);
	va_end(ap);
	return (result);
}