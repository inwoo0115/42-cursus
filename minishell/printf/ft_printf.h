/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:51:20 by wonjilee          #+#    #+#             */
/*   Updated: 2023/07/20 20:51:21 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_error_printf(const char *format, ...);
char	*ft_pitoa(long long n);
int		ft_printf_char(int c);
int		ft_printf_str(char *str);
int		ft_printf_nbr(int nbr);
int		ft_printf_unsigned(unsigned int nbr);
int		ft_printf_hex(unsigned int nbr, const char type);
int		ft_printf_ptr(unsigned long long ptr);
size_t	ft_pstrlen(const char *str);
size_t	n_count(long long nb, int len);
int		ft_pputchar_fd(char c, int fd);
int		ft_pputstr_fd(char *s, int fd);
int		ft_pputnbr_base(long long nb, char *base);

#endif