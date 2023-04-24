# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjin <wonjilee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 21:39:26 by wonjilee          #+#    #+#              #
#    Updated: 2023/04/24 11:47:19 by wonjin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex
CC = cc
CFLAG = -Wall -Wextra -Werror -o3

SRCS = main.c pipex_split.c set_data.c start_pipe.c utils.c

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

$(NAME): $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -o $@


.PHONY: all clean fclean re bonus