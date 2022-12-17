/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:23:31 by wonjin            #+#    #+#             */
/*   Updated: 2022/12/05 21:31:00 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

enum e_convert { PLAIN, CHAR, STR, PTR, SDEC, UDEC, LHEX, UHEX, PCENT };

typedef struct s_convert
{
	int		index;
	char	*start;
	char	*end;
	int		width;
	int		precision;
	int		u_width;
	int		u_zero;
	int		u_precision;
	int		u_alt;
	int		u_blank;
	int		u_plus;
}	t_convert;

typedef struct s_list
{
	t_convert	*convert;
	t_list		*next;
}	t_list;

#endif