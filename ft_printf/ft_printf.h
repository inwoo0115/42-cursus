/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:23:31 by wonjin            #+#    #+#             */
/*   Updated: 2023/01/20 20:54:01 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	print_format(va_list ap, const char *locate);
int	start_print(va_list ap, const char *format);
int	print_char(char c);
int	print_str(char *str);
int	print_ptr(void *ptr);
int	print_int(int num);
int	print_udec(unsigned int num);
int	print_lhex(unsigned int num);
int	print_uhex(unsigned int num);
int	print_pcent(void);
int	ft_itoa(long long num);
int	ft_lhex(size_t num);
int	ft_uhex(size_t num);

#endif