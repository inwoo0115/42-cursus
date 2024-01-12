CC 		=	c++

CFLAGS 	=	-std=c++98 -Wall -Wextra -Werror

NAME 	=	harlFilter

SRCS	=	main.cpp Harl.cpp

OBJS 	=	$(SRCS:%.cpp=%.o)

%.o		:	%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -o $@

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : 
		make fclean 
		make all

.PHONY: all clean fclean re