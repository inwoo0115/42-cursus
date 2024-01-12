CC 		=	c++

CFLAGS 	=	-std=c++98 -Wall -Wextra -Werror

NAME 	=	ex00

SRCS	=	main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

OBJS 	=	$(SRCS:%.cpp=%.o)

%.o		:	%.cpp
			$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : 
		make fclean 
		make all

.PHONY: all clean fclean re