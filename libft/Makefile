# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaveric <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 19:36:08 by emaveric          #+#    #+#              #
#    Updated: 2019/04/21 15:41:22 by emaveric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_div_mod.c ft_is_whitespaces.c ft_isalnum.c \
	  ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	  ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
	  ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
	  ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	  ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_recursive_factorial.c \
	  ft_sqrt.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
	  ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	  ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	  ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
	  ft_strtrim.c ft_swap.c ft_tolower.c ft_toupper.c

OBJ = ft_atoi.o ft_lstiter.o ft_putendl.o ft_strdel.o ft_strnequ.o \
	  ft_bzero.o ft_lstmap.o ft_putendl_fd.o ft_strdup.o ft_strnew.o \
	  ft_div_mod.o ft_lstnew.o ft_putnbr.o ft_strequ.o ft_strnstr.o \
	  ft_is_whitespaces.o  ft_memalloc.o   ft_putnbr_fd.o   ft_striter.o \
	  ft_strrchr.o ft_isalnum.o ft_memccpy.o ft_putstr.o ft_striteri.o \
	  ft_strsplit.o ft_isalpha.o ft_memchr.o ft_putstr_fd.o ft_strjoin.o \
	  ft_strstr.o ft_isascii.o ft_memcmp.o ft_recursive_factorial.o \
	  ft_strlcat.o ft_strsub.o ft_isdigit.o ft_memcpy.o ft_sqrt.o \
	  ft_strlen.o ft_strtrim.o ft_isprint.o ft_memdel.o ft_strcat.o \
	  ft_strmap.o ft_swap.o ft_itoa.o ft_memmove.o ft_strchr.o \
	  ft_strmapi.o ft_tolower.o ft_lstadd.o ft_memset.o ft_strclr.o \
	  ft_strncat.o ft_toupper.o ft_lstdel.o ft_putchar.o ft_strcmp.o \
	  ft_strncmp.o ft_lstdelone.o ft_putchar_fd.o ft_strcpy.o ft_strncpy.o

HEAD = -I libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(HEAD) $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
