# Main
NAME				=	ex00
CC					=	c++

# -Wall -Werror -Wextra
CFLAGS				=	-Wall -Werror -Wextra -std=c++98
RM					=	rm -rf

# Colors
RESET				=	\033[0m
GREEN				=	\033[1;32m

SRCS				=	main.cpp\
						Bureaucrat.cpp\
						AForm.cpp\
						Intern.cpp\
						ShrubberyCreationForm.cpp\
						RobotomyRequestForm.cpp\
						PresidentialPardonForm.cpp\

OBJS				=	$(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) $< -c

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
