# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 00:14:10 by wonjilee          #+#    #+#              #
#    Updated: 2023/04/10 21:49:30 by wonjilee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
CC = cc
CFLAG = -Wall -Wextra -Werror -o3

SRCS = ./src/fractol.c ./src/put_image.c ./src/set_hook.c ./src/init.c

SRCS_BONUS = 

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME) $(NAME_BONUS)

%.o : %.c
		$(CC) $(CFLAG) -Imlx -c $< -o $@ -I ./srcs

clean :
		rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
		rm -f $(NAME) $(NAME_BONUS)

re : 
		make fclean 
		make all

$(NAME): $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

$(NAME_BONUS): $(OBJS_BONUS)
		$(CC) $(CFLAG) $(OBJS_BONUS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

.PHONY: all clean fclean re bonus