# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 16:23:39 by otuyishi          #+#    #+#              #
#    Updated: 2024/04/06 12:31:50 by otuyishi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -I./includes -fsanitize=address

RM = rm -rf

NAME = ex02

SRCS = main.cpp srcs/Bureaucrat.cpp srcs/AForm.cpp \
		srcs/PresidentialPardonForm.cpp srcs/RobotomyRequestForm.cpp \
		srcs/ShrubberyCreationForm.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
		${CC} ${CFLAGS} -c $< -o $@

clean:
		$(RM) $(OBJS) ex00

fclean: clean
		$(RM) $(NAME)

re: fclean all

run: all clean
		./$(NAME)

.PHONY: all clean fclean re run
