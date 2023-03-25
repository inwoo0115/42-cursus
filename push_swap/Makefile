# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 23:29:33 by wonjilee          #+#    #+#              #
#    Updated: 2023/03/25 23:49:06 by wonjilee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
NAME_BONUS = checker
CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS = ./srcs/arr_utils.c ./srcs/command_print.c ./srcs/command.c ./srcs/ft_sort.c ./srcs/ft_split.c \
./srcs/push_swap.c ./srcs/single_sort.c ./srcs/command_operate.c ./srcs/init.c

SRCS_BONUS = ./bonus/arr_utils_bonus.c ./bonus/checker_bonus.c ./bonus/command_bonus.c \
./bonus/command_print_bonus.c ./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c \
./bonus/ft_split_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME) $(NAME_BONUS)

%.o : %.c
		$(CC) $(CFLAG) -c $< -o $@ -I ./srcs

clean :
		rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
		rm -f $(NAME) $(NAME_BONUS)

re : 
		make fclean 
		make all

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $? -o $@

$(NAME_BONUS): $(OBJS_BONUS)
		$(CC) $(CFLAGS) $? -o $@

.PHONY: all clean fclean re bonus
