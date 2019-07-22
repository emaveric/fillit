# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaveric <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/28 20:04:11 by emaveric          #+#    #+#              #
#    Updated: 2019/05/28 20:07:08 by emaveric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.a

SRC = *.c

OBJ = *.o

HEAD = -I fillit.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(HEAD) $(SRC)
	ar rc $(OBJ) $(NAME)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
