# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 00:14:10 by wonjilee          #+#    #+#              #
#    Updated: 2023/03/26 00:15:50 by wonjilee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS = 

SRCS_BONUS = 

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