# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 16:11:41 by wonjilee          #+#    #+#              #
#    Updated: 2023/08/05 20:20:09 by wonjilee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
CC = cc
CFLAG = -Wall -Wextra -Werror #-g -fsanitize=thread

SRCS = main.c ft_init.c ft_monitoring.c ft_thread.c utils.c ft_print.c

#SRCS_BONUS = 

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
