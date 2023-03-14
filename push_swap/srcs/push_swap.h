/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:47:09 by wonjilee          #+#    #+#             */
/*   Updated: 2023/03/14 22:25:30 by wonjilee         ###   ########.fr       */
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
	int	tri;
	int	left;
	int	tri_left;
	int	b_top;
	int	b_bot;
	int	a_bot;
	int	bt_num;
	int	bb_num;
	int	ab_num;
}	t_info;

typedef struct s_cmd
{
	int	num[4];
	int	bt_cmd;
	int	bb_cmd;
	int	ab_cmd;
}	t_cmd;

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

enum e_tri
{
	ABOT = 1,
	BTOP = 2,
	BBOT = 3,
	NONE = 100
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
void	check_tri(t_info *data, t_stack *a);
void	merge_tri(t_info *data, t_stack *a, t_stack *b, int result);
int		compare_num(t_stack *a, t_stack *b, int top, t_info *data);
int		new_max(t_stack *a, t_stack *b, int temp, t_info *data);

//merge_sort
int		find_tri(t_info *data, t_stack *a);
void	pass_tri_2(t_info *data, t_stack *a, t_stack *b, int next);
void	pass_tri(t_info *data, t_stack *a, t_stack *b, int i);
void	pass_tri_left(t_info *data, t_stack *a, t_stack *b, int i);
void	pass_tri_left1(t_info *data, t_stack *a, t_stack *b, int next);

//single_sort
void	single_sort(t_stack *a, t_stack *b, int size);
void	sort_size3(t_stack *a, t_stack *b);
void	sort_size4(t_stack *a, t_stack *b);
void	sort_size5(t_stack *a, t_stack *b);

//small_sort
void	small_sort(t_stack *a, t_stack *b, int size);
void	small_sort_size3(t_stack *a, t_stack *b, int next, int last);

//local_sort1
void	local_sort(t_info *data, t_stack *a, t_stack *b);
void	init_num(t_stack *a, t_cmd *cmd, int temp, int num);
void	check_command(t_info *data, t_cmd *cmd);

//local_sort2
int		ab_command(t_cmd *cmd, int num);
int		ab_command1(t_cmd *cmd, int num);
int		bb_command(t_cmd *cmd, int num);
int		bt_command(t_cmd *cmd, int num);

//local_sort3
void	local_abot(t_stack *a, t_stack *b, t_cmd cmd);
void	local_abot_num0(t_stack *a, t_stack *b, t_cmd cmd);
void	local_abot_num1(t_stack *a, t_stack *b, t_cmd cmd);
void	local_abot_num2(t_stack *a, t_stack *b, t_cmd cmd);
void	local_abot_num3(t_stack *a, t_stack *b, t_cmd cmd);

//local_sort4
void	local_btop(t_stack *a, t_stack *b, t_cmd cmd);
void	local_btop_num0(t_stack *a, t_stack *b, t_cmd cmd);
void	local_btop_num1(t_stack *a, t_stack *b, t_cmd cmd);
void	local_btop_num2(t_stack *a, t_stack *b, t_cmd cmd);
void	local_btop_num3(t_stack *a, t_stack *b, t_cmd cmd);

//local_sort5
void	local_bbot(t_stack *a, t_stack *b, t_cmd cmd);
void	local_bbot_num0(t_stack *a, t_stack *b, t_cmd cmd);
void	local_bbot_num1(t_stack *a, t_stack *b, t_cmd cmd);
void	local_bbot_num2(t_stack *a, t_stack *b, t_cmd cmd);
void	local_bbot_num3(t_stack *a, t_stack *b, t_cmd cmd);
#endif