# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviles- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 16:39:43 by daviles-          #+#    #+#              #
#    Updated: 2023/05/19 18:04:47 by daviles-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	  ft_putchar.c \
	  ft_putnbr.c \
	  ft_putnbrbase.c \
	  ft_putpointer.c \
	  ft_putstr.c \
	  ft_putunsigned.c
OBJ = $(SRC:.c=.o)

CC	= gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ) 
	$(AR) $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)


re : fclean all

.PHONY : all NAME clean fclean re 
