SRCS			=	main.cpp\
					Zombie.cpp\
					ZombieHorde.cpp
					
CLA				= clang++
RM				= rm -f
CLAFLAGS		= -Wall -Wextra -Werror -std=c++98
	
OBJS			= $(SRCS:.cpp=.o)

%.o:		%.cpp
			$(CLA) $(CLAFLAGS) -c $< -o $@
			

NAME			= zombie

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CLA) $(CLAFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re test