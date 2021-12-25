SRCS			=	mutantstack.cpp\
					main.cpp

CLA				= clang++
RM				= rm -f
CLAFLAGS		= -Wall -Wextra -Werror -std=c++11
#CLAFLAGS		= -g -Wall -Wextra -Werror -std=c++98
	
OBJS			= $(SRCS:.cpp=.o)

%.o:		%.cpp
			$(CLA) $(CLAFLAGS) -c $< -o $@
			

NAME			= a.out

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CLA) $(CLAFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re test