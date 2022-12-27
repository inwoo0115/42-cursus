/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:45:31 by wonjilee          #+#    #+#             */
/*   Updated: 2022/12/27 22:41:35 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_line
{
	char	buff[BUFFER_SIZE + 1];
	char	save[BUFFER_SIZE + 1];
	int		index;
	int		len;
}	t_line;

char	*get_next_line(int fd);
char	*make_line(char *str, t_line *data);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*free_res(char *str);
int		next_line(char *str, t_line *data);
int		check_read(int fd, t_line *data);
size_t	ft_strlen(char *s);

#endif