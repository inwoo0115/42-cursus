/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:23:31 by wonjin            #+#    #+#             */
/*   Updated: 2023/01/16 22:58:50 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	print_char(char c);
int	print_str(char *str);
int	print_ptr(void *ptr);
int	print_dec(int num);
int	print_int(int num);
int	print_udec(unsigned int num);
int	print_lhex(unsigned int num);
int	print_uhex(unsigned int num);
int	print_pcent(void);
int	ft_itoa(long long num);
int	ft_lhex(unsigned int num);
int	ft_uhex(unsigned int num);

#endif