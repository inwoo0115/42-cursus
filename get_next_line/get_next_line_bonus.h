/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 02:47:41 by wonjilee          #+#    #+#             */
/*   Updated: 2023/01/24 05:28:23 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
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
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*make_line(char	*str, t_list *data, t_list **head, int fd);
char	*get_newline(int fd, char *buff, t_list *data, int len);
char	*find_data(t_list *data, int i);
char	*ft_strjoin(char *s1, char *s2);
int		check_newline(char *str, t_list *data, int i, int j);
size_t	ft_strlen(char *s);
t_list	*check_data(t_list **head, int fd);
void	create_data(t_list *data, int fd);
char	*free_res(t_list *data, t_list **head, int fd);

#endif