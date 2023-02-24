/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:47:09 by wonjilee          #+#    #+#             */
/*   Updated: 2023/02/25 05:24:23 by wonjilee         ###   ########.fr       */
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
	int	tri; //size 4 삼각형의 갯수
	int	left; // 남은 숫자의 갯수
	int	tri_left; //남은 삼각형의 갯수
	int	b_top; //b_top 에 들어간 삼각형의 갯수
	int	b_bot; //b_bot에 들어간 삼각형의 갯수
	int	a_bot; //a_bot에 들어간 삼각형의 갯수
	int	bt_num; //b_top 에 들어간 숫자의 갯수
	int	bb_num;
	int	ab_num;
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
	RRR
};

enum e_tri
{
	ABOT;
	BTOP;
	BBOT;
};

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

//command_print
void	ps_command(int order, t_stack *a, t_stack *b);
void	r_command(int order, t_stack *a, t_stack *b);
void	d_command(int order, t_stack *a, t_stack *b);

#endif