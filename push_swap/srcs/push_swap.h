/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:47:09 by wonjilee          #+#    #+#             */
/*   Updated: 2023/04/01 21:04:01 by wonjilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		size;
	int		front;
	int		rear;
	int		*data;
}	t_stack;

typedef struct s_info
{
	int	a_rotate;
	int	b_rotate;
	int	a_num;
	int	b_num;
}	t_info;

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
	UP,
	DOWN
};

//main
int		free_res(t_stack *a, t_stack *b);
int		check_sort(t_stack *a);

//arr_utils
int		ft_atoi(char *str, int *error, int num, int temp);
void	make_arr(t_stack *a, int argc, char *argv[], int idx);
void	make_stack(t_stack *a, int argc, char *argv[]);
void	ft_error(t_stack *a);
void	check_arr(t_stack *a);

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

//command_print
void	p_command(int order, t_stack *a, t_stack *b);
void	r_command(int order, t_stack *a, t_stack *b);
void	d_command(int order, t_stack *a, t_stack *b);
void	s_command(int order, t_stack *a, t_stack *b);

//ft_sort
void	ft_sort(t_stack *a, t_stack *b);
void	find_min_cmd(t_stack *a, t_stack *b, t_info *data, int temp);
void	check_count_a(t_stack *a, t_info *data, int val, int size);
void	check_count_b(t_stack *b, t_info *data, int index, int size);
int		find_index_a(t_stack *a, int val, int curr);

//command_operate
void	cmd_operate(t_stack *a, t_stack *b, t_info *data);
void	operate_ab(t_stack *a, t_stack *b, t_info *data);
int		find_min_num(t_stack *a, int curr, int i);
void	operate_a(t_stack *a, t_stack *b, int min);

//init
void	init_stack(t_stack *a, t_stack *b, int size, int p1);
int		check_size(t_stack *a, int i);
int		find_pivot(t_stack *a, int index, int i);

//single_sort
void	single_sort(t_stack *a, t_stack *b, int size);
void	sort_size3(t_stack *a, t_stack *b);
void	sort_size4(t_stack *a, t_stack *b);
void	sort_size5(t_stack *a, t_stack *b);

#endif