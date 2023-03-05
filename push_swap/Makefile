# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 23:29:33 by wonjilee          #+#    #+#              #
#    Updated: 2023/03/05 21:23:39 by wonjilee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
NAME_BONUS = checker
CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS = ./srcs/arr_utils.c ./srcs/command_print.c ./srcs/command.c ./srcs/ft_sort.c ./srcs/ft_split.c ./srcs/local_sort1.c \
./srcs/local_sort2.c ./srcs/local_sort3.c ./srcs/local_sort4.c ./srcs/local_sort5.c ./srcs/merge_sort.c ./srcs/push_swap.c \
./srcs/single_sort.c ./srcs/small_sort.c

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
