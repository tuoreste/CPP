# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 10:16:42 by otuyishi          #+#    #+#              #
#    Updated: 2024/02/25 21:30:42 by otuyishi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03
SRCS = main.cpp Character.cpp MateriaSource.cpp Ice.cpp Cure.cpp AMateria.cpp
OBJS = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror -std=c++98  -Wshadow -Wno-shadow

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
