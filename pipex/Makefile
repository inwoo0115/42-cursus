# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 21:39:26 by wonjilee          #+#    #+#              #
#    Updated: 2023/04/28 18:13:49 by wonjilee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex
CC = cc
CFLAG = -Wall -Wextra -Werror -o3

SRCS = ./srcs/main.c ./srcs/pipex_split.c ./srcs/set_data.c ./srcs/start_pipe.c ./srcs/utils.c

SRCS_BONUS = ./bonus/main_bonus.c ./bonus/pipex_split_bonus.c ./bonus/set_data_bonus.c ./bonus/start_pipe_bonus.c \
./bonus/utils_bonus.c ./bonus/get_next_line_bonus.c ./bonus/get_next_line_utils_bonus.c ./bonus/ft_heredoc_bonus.c


OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME)

%.o : %.c
		$(CC) $(CFLAG) -c $< -o $@ -I ./srcs -I ./bonus

clean :
		rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
		rm -f $(NAME)

re : 
		make fclean 
		make all

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME): $(OBJS_BONUS)
		$(CC) $(CFLAG) $(OBJS_BONUS) -o $@
else
$(NAME): $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -o $@
endif

.PHONY: all clean fclean re bonus