SRCS			= PhoneBook.cpp
OBJS			= $(SRCS:.cpp=.o)

CLA				= clang++
RM				= rm -f
CLAFLAGS		= -Wall -Wextra -Werror

NAME			= a.out

%.o:		%.cpp
			$(CLA) $(CLAFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CLA) $(CLAFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re test