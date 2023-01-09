/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:14:01 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/09 13:15:42 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*free_res(char *str, char *data);
char	*make_line(char *str, char *data, int i, int j);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(int fd, char data[][BUFFER_SIZE + 1]);
int		next_line(char *str);
size_t	ft_strlen(char *s);

#endif