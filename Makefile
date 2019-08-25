# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaveric <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/28 20:04:11 by emaveric          #+#    #+#              #
#    Updated: 2019/08/25 17:48:01 by emaveric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean all re

NAME = fillit

LIB_DIR = libft

SRC = main.c ft_new_field.c ft_figure_coordinates.c ft_is_figure_valid.c

OBJ = $(SRC:.c=.o)

LIB = libft.a

R_LIB = make -C $(LIB_DIR)

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -L $(LIB_DIR) -lft

all: $(NAME)

$(LIB):
	$(R_LIB)

%.o:%.c
	gcc -c $(CFLAGS) -I. $<

$(NAME): $(LIB) $(OBJ)
	@gcc $(CFLAGS) $(LFLAGS) -I. -o $@ $(OBJ)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
