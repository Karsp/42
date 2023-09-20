# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviles- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 14:00:44 by daviles-          #+#    #+#              #
#    Updated: 2023/09/20 14:20:07 by daviles-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#########################        LIBS        #################################

NAMELIB	=	srcs/push_swap.a

LIB 	=	libft/libft.a

##########################    DIRS     ####################################

SRC_DIR = srcs

###########################    FILES   ####################################

SRC = $(addprefix $(SRC_DIR)/, main.c utils.c parse.c setinit.c \
	  handle_nodes.c moves_swpu.c moves_rr.c sort.c set_position.c \
	  set_distance.c sort_small.c)

OBJ = $(SRC:.c=.o)

##########################   COMPILING SETTINGS   #########################

CC	= gcc

CFLAGS = -Wall -Wextra -Werror #-O3 -fsanitize=address -g3

COMP = $(CC) $(CFLAGS) $(LIB) 

RM = rm -f

###########################    EXTRAS   ####################################

NOC		=	\033[0m
GREEN	=	\033[1;32m
YELLOW = \033[1;33m
BLUE	=	\033[1;34m
RED		=	\033[1;31m

all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) bonus -sC ./libft
	$(COMP) $(OBJ) -o $@
	@echo "$(GREEN)\n Push_Swap is ready to go!$(NOC)"
	@echo "$(YELLOW)    _       _       _"
	@echo " __(.)<  __(.)>  __(.)="
	@echo " \___)   \___)   \___)$(NOC)"
	@echo "$(GREEN)\nRun ./Push_swap and write your list in one string, or separated by spaces.\n$(NOC)"

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJ)
	$(MAKE) fclean -sC ./libft

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
