# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 16:11:41 by wonjilee          #+#    #+#              #
#    Updated: 2023/08/09 14:14:43 by wonjilee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS = main.c ft_init.c ft_monitoring.c ft_thread.c utils.c ft_print.c error.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
		$(CC) $(CFLAG) -c $< -o $@

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : 
		make fclean 
		make all

$(NAME): $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -o $@

.PHONY: all clean fclean re bonus
