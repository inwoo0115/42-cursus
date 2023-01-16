# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 15:17:45 by wonjilee          #+#    #+#              #
#    Updated: 2023/01/16 18:58:25 by wonjilee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC = cc
CFLAG = -Wall -Wextra -Werror

INCLUDES = ./ft_printf.h

SRCS = ft_printf.c ft_printf_function.c ft_printf_function2.c

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
		ar crsu $@ $?

.PHONY: all clean fclean re
