
EXE = fractol

EXELIB	=	libftfractol.a

#LIB 	=	libft/libft.a

SRC = ft_fractol.c \

OBJ = $(SRC:.c=.o)

CC	= gcc

CFLAGS = -Wall -Wextra -fsanitize=address -g3

MLX = -lmlx -framework OpenGL -framework AppKit -L ./mlx 

COMP = $(CC) $(CFLAGS) $(LIB) $(MLX) 

RM = rm -f

all : $(EXE)

$(EXE) : $(OBJ)
	 $(COMP) $(OBJ) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(EXE)


re : fclean all

.PHONY : all EXE clean fclean re
