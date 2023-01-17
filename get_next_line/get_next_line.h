/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:10:45 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/17 22:07:38 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*get_newline(int fd, char *buff, char *data, int len);
char	*make_data(char *str);
char	*make_line(char	*str);
int		check_newline(char *data);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);

#endif