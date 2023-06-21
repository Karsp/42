# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviles- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 14:00:44 by daviles-          #+#    #+#              #
#    Updated: 2023/06/21 15:25:56 by daviles-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE = fractol

#########################        LIBS        #################################

EXELIB	=	libftfractol.a

LIB 	=	libft/libft.a

##########################    DIRS     ####################################

SRC_DIR = srcs

SRC_BONUS_DIR = bonus

###########################    FILES   ####################################

SRC = $(addprefix $(SRC_DIR)/, ft_fractol.c set_init.c color.c render.c events.c actions.c \
	  mandelbrot.c sort.c julia.c burning_ship.c)

SRC_BONUS = $(addprefix $(SRC_BONUS_DIR)/, actions_bonus.c ft_fractol.c set_init.c color.c \
	  render.c events.c mandelbrot.c sort.c julia.c burning_ship.c)

OBJ = $(SRC:.c=.o)

B_OBJ = $(SRC_BONUS: .c=.o)

##########################   COMPILING SETTINGS   #########################

CC	= gcc

CFLAGS = -Wall -Wextra# -fsanitize=address -g3

MLX = -lmlx -framework OpenGL -framework AppKit -L ./mlx

COMP = $(CC) $(CFLAGS) $(LIB) $(MLX)

RM = rm -f

###########################    EXTRAS   ####################################

NOC		=	\033[0m
GREEN	=	\033[1;32m
YELLOW = \033[1;33m
BLUE	=	\033[1;34m
RED		=	\033[1;31m


all : $(EXE)

$(EXE) : $(OBJ)
	$(MAKE) bonus -C ./libft
	$(COMP) $(OBJ) -o $@

bonus :	$(B_OBJ)
	$(MAKE) bonus -C ./libft
	$(COMP) $(B_OBJ) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJ)
	$(RM) $(B_OBJ)
	$(MAKE) fclean -C ./libft

fclean : clean
	$(RM) $(EXE)

re : fclean all

.PHONY : all clean fclean re bonus
