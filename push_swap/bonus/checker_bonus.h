/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:29:52 by wonjilee          #+#    #+#             */
/*   Updated: 2023/03/26 00:07:39 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		size;
	int		front;
	int		rear;
	int		*data;
}	t_stack;

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
	RRR,
	OK,
	KO
};

typedef struct s_list
{
	int				fd;
	int				index;
	int				len;
	char			buff[5];
}	t_list;

//checker
int		free_res(t_stack *a, t_stack *b);
int		check_sort(t_stack *a, t_stack *b, int i);
void	print_result(int result);
void	get_command(t_stack *a, t_stack *b);

//arr_utils
void	make_stack(t_stack *a, int argc, char *argv[]);
void	make_arr(t_stack *a, int argc, char *argv[], int idx);
void	check_arr(t_stack *a);
void	ft_error(t_stack *a);
int		ft_atoi(char *str, int *error, int num, int temp);

//command
void	push(t_stack *from, t_stack *to);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	re_rotate(t_stack *stack);

//comand print
void	cmd_operate(int order, t_stack *a, t_stack *b);
void	d_command(int order, t_stack *a, t_stack *b);
int		command_check(char	*str);

//get_next_line
char	*get_next_line(int *error);
char	*make_line(char	*str);
char	*get_newline(int *error, char *buff, t_list *data, int len);
char	*find_data(t_list *data, int i);
char	*ft_strjoin(char *s1, char *s2);
int		check_newline(char *str, t_list *data, int i, int j);
size_t	ft_strlen(char *s);
char	*error_return(int *error);

//ft_split
char	**make_split(char const *s, char c, char **split_word);
int		num_word(char const *s, char c);
int		num_letter(char const *s, char c, int i);
char	**split_free(char **split_word);
char	**ft_split(char const *s, char c, int *error);
#endif