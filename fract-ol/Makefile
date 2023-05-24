
EXE = fractol

SRC = ft_fractol.c \

OBJ = $(SRC:.c=.o)

CC	= gcc

CFLAGS = -Wall -Wextra -Werror

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit 

RM = rm -f

all : $(EXE)

$(EXE) : $(OBJ)
	 $(CC) $(OBJ) $(MLX) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -Ilmx -c -o $@ $<

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(EXE)


re : fclean all

.PHONY : all EXE clean fclean re