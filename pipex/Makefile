# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviles- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 14:00:44 by daviles-          #+#    #+#              #
#    Updated: 2023/10/25 22:48:57 by daviles-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

#########################        LIBS        #################################

NAMELIB	=	include/pipex.a

BONUSLIB	= include/pipex_bonus.a

LIB 	=	libft/libft.a

##########################    DIRS     ####################################

SRC_DIR = srcs

###########################    FILES   ####################################

MAIN = $(addprefix $(SRC_DIR)/, main.c)

SRC = $(addprefix $(SRC_DIR)/, pipex.c childs.c utils.c parser.c)

OBJ = $(SRC:.c=.o) $(MAIN:.c=.o)

##########################   FILES BONUS   ################################

MAIN_BONUS = ./bonus/main_bonus.c

SRC_BONUS = ./bonus/pipex_bonus.c ./bonus/childs_bonus.c

OBJS_BONUS = $(MAIN_BONUS:.c=.o) $(SRC_BONUS:.c=.o) $(SRC:.c=.o)

##########################   COMPILING SETTINGS   #########################

CC	= gcc

CFLAGS = -Wall -Wextra -Werror -O3 -fsanitize=address -g3

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
	@echo "$(GREEN)\n Pipex is ready to go!$(NOC)"
	@echo "$(YELLOW)    _       _       _"
	@echo " __(.)<  __(.)>  __(.)="
	@echo " \___)   \___)   \___)$(NOC)"
	@echo "$(GREEN)\nProgram is ready to use! Run ./pipex to see instructions.\n$(NOC)"

bonus : $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(MAKE) bonus -sC ./libft
	$(COMP) $(OBJS_BONUS) -o pipex

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJ) $(OBJS_BONUS)
	$(MAKE) fclean -sC ./libft

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
