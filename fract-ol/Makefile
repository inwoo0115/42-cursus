# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonjilee <wonjilee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 00:14:10 by wonjilee          #+#    #+#              #
#    Updated: 2023/04/16 21:20:32 by wonjilee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
CC = cc
CFLAG = -Wall -Wextra -Werror -o3

SRCS = ./src/fractol.c ./src/put_image.c ./src/set_hook.c ./src/init.c ./src/put_fractol.c

SRCS_BONUS = ./bonus/fractol_bonus.c ./bonus/put_image_bonus.c ./bonus/set_hook_bonus.c ./bonus/init_bonus.c ./bonus/put_fractol_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME)

%.o : %.c
		$(CC) $(CFLAG) -Imlx -c $< -o $@ -I ./srcs

clean :
		rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
		rm -f $(NAME)

re : 
		make fclean 
		make all

ifeq ($(findstring bonus, $(MAKECMDGOALS)), bonus)
$(NAME): $(OBJS_BONUS)
		$(CC) $(CFLAG) $(OBJS_BONUS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@
else
$(NAME): $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@
endif

.PHONY: all clean fclean re bonus