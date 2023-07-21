# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunhcho <eunhcho@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 20:52:24 by wonjilee          #+#    #+#              #
#    Updated: 2023/07/20 20:58:14 by eunhcho          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		=	cc

CFLAGS 	=	-Wall -Wextra -Werror

FTPRINTF_DIR = ./printf/
FTPRINTF_LIB = $(FTPRINTF_DIR)libftprintf.a
FTPRINTF_FLAG = -L$(FTPRINTF_DIR) -lftprintf

INCLUDE =	-I $(HOME)/.brew/opt/readline/include -I$(FTPRINTF_DIR)

LIBRARY	=	-L $(HOME)/.brew/opt/readline/lib -lreadline

NAME 	=	minishell

SRCS 	=	./minishell.c ./utils/ft_heredoc_utils.c \
			./utils/ft_signal.c ./utils/ft_error.c \
			./utils/ft_run_exec_utils.c \
			./utils/ft_putstr_fd.c ./utils/ft_isalpha.c \
			./utils/ft_isdigit.c ./utils/ft_split.c \
			./utils/ft_strcmp.c ./utils/ft_strjoin.c \
			./utils/ft_strlen.c ./utils/ft_strdup.c \
			./utils/ft_free.c ./utils/ft_atoi.c ./utils/ft_export_utils.c\
			./utils/ft_free_utils.c ./utils/ft_parse_utils.c\
			./parse/ft_create_node.c ./parse/ft_init_cmd.c \
			./parse/ft_init_main.c ./parse/ft_init_parse.c \
			./parse/ft_parse_dollar.c ./parse/ft_parse_envp.c \
			./parse/ft_parse_in_red.c ./parse/ft_parse_letter.c \
			./parse/ft_parse_out_red.c ./parse/ft_parse_pipe.c \
			./parse/ft_parse_space.c ./parse/ft_run_heredoc.c \
			./execution/ft_redirect.c ./execution/ft_run_exec.c \
			./execution/ft_run_pipe.c ./execution/ft_start_main.c \
			./builtin/ft_echo.c ./builtin/ft_env.c \
			./builtin/ft_exit.c ./builtin/ft_pwd.c \
			./builtin/ft_unset.c ./builtin/ft_cd.c \
			./builtin/ft_export.c

OBJS 	=	$(SRCS:%.c=%.o)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDE)

all		:	$(NAME)

$(FTPRINTF_LIB):
			make -C $(FTPRINTF_DIR)

$(NAME)	:	$(FTPRINTF_LIB) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME) $(LIBRARY) $(FTPRINTF_FLAG)

clean	:
			rm -rf $(OBJS)
			make clean -C $(FTPRINTF_DIR)

fclean	:	clean
			rm -rf $(NAME)
			make fclean -C $(FTPRINTF_DIR)

re		:	fclean
			make all

.PHONY	:	all clean fclean re
