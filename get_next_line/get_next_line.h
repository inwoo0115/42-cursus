/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:08:00 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/24 05:18:36 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	int				fd;
	int				index;
	int				len;
	char			buff[BUFFER_SIZE + 1];
}	t_list;

char	*get_next_line(int fd);
char	*make_line(char	*str);
char	*get_newline(int fd, char *buff, t_list *data, int len);
char	*find_data(t_list *data, int i);
char	*ft_strjoin(char *s1, char *s2);
int		check_newline(char *str, t_list *data, int i, int j);
size_t	ft_strlen(char *s);

#endif