/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:23:31 by wonjin            #+#    #+#             */
/*   Updated: 2022/12/28 15:35:46 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

enum e_convert {PLAIN, CHAR, STR, PTR, DEC, IDEC, UDEC, LHEX, UHEX, PCENT};

typedef struct s_convert
{
	int		index;
	char	*start;
	char	*end;
}	t_convert;

typedef struct s_list
{
	t_convert	*convert;
	t_list		*next;
}	t_list;

int			ft_printf(const char *format, ...);
int			add_convert(t_list **converts, t_convert *new_convert);
int			check_conversion(t_list **converts, char **locate);
int			check_format(t_list **converts, const char *format);
int			add_plain(t_list **converts, char *temp, char *locate);
int			start_print(t_list *converts, va_list ap);
int			print_convert(t_convert *text, va_list ap);
int			check_flags(char **locate);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst);
t_convert	*create_convert(void);

int			print_plain(t_convert *text);
int			print_char(t_convert *text, char c);
int			print_str(t_convert *text, char *str);
int			print_dec(t_convert *text, int num);
int			print_idec(t_convert *text, int num);
int			print_udec(t_convert *text, int num);
int			print_lhex(t_convert *text, int num);
int			print_udex(t_convert *text, int num);
int			print_pcent(t_convert *text);

#endif