NAME	= bureaucrat

SRC		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp Intern.cpp

OBJ		= $(SRC:.cpp=.o)

CXX		= c++

CXXFLAG	= -Wall -Wextra -Werror -std=c++98 

all		:	${NAME}

${NAME}	:	${OBJ}
	${CXX} ${CXXFLAG} -o ${NAME} ${OBJ}

%o		:	%.cpp
	${CXX} ${CXXFLAG} -c $< -o $@

clean	:
	rm -f ${OBJ}

fclean	:	clean
	rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re