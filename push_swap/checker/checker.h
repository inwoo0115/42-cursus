/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:06:08 by wonjilee          #+#    #+#             */
/*   Updated: 2023/02/20 20:32:00 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_stack
{
	int		size;
	int		front;
	int		rear;
	int		*data;
}	t_stack;

typedef struct s_list
{
	int				fd;
	int				index;
	int				len;
	char			buff[BUFFER_SIZE + 1];
}	t_list;

enum e_cmd
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

//main
int	free_res(t_stack *a, t_stack *b);
int	check_stack(t_stack *a, t_stack *b);

//arr_utils
int		ft_atoi(char *str, int *error, int num, int temp);
void	make_arr(t_stack *a, int argc, char *argv[], int idx);
void	make_stack(t_stack *a, int argc, char *argv[]);
void	ft_error(t_stack *a);

//ft_split
char	**make_split(char const *s, char c, char **split_word);
int		num_word(char const *s, char c);
int		num_letter(char const *s, char c, int i);
char	**split_free(char **split_word);
char	**ft_split(char const *s, char c, int *error);

//command
void	push(t_stack *from, t_stack *to);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	re_rotate(t_stack *stack);

//command_use
void	s_command(int order, t_stack *a, t_stack *b);
void	d_command(int order, t_stack *a, t_stack *b);

//gnl
char	*get_next_line(int fd);
char	*make_line(char	*str);
char	*get_newline(int fd, char *buff, t_list *data, int len);
char	*find_data(t_list *data, int i);
char	*ft_strjoin(char *s1, char *s2);
int		check_newline(char *str, t_list *data, int i, int j);
size_t	ft_strlen(char *s);

#endif