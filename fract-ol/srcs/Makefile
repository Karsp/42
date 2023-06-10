
EXE = fractol

EXELIB	=	libftfractol.a

LIB 	=	libft/libft.a

SRCS_DIR = srcs

SRCS_BONUS_DIR = bonus

SRCS_DIR = bonus

SRC = f$(addprefix $(SRCS_BONUS_DIRECTORY)/, t_fractol.c set_init.c \
	  color.c render.c events.c actions.c \
	  mandelbrot.c sort.c julia.c)

SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIRECTORY)/, \
		 ft_fractol.c set_init.c color.c render.c events.c actions.c \
	  mandelbrot.c sort.c julia.c)

OBJ = $(SRC:.c=.o)

B_OBJ = $(SRCS_BONUS:.c=.o)

CC	= gcc

CFLAGS = -Wall -Wextra -fsanitize=address -g3

MLX = -lmlx -framework OpenGL -framework AppKit -L ./mlx 

COMP = $(CC) $(CFLAGS) $(LIB) $(MLX) 

RM = rm -f

ifdef BONUS
	OBJECTS = $(B_OBJ)
else
	OBJECTS = $(OBJ)
endif

all : $(EXE)

$(EXE) : $(OBJECTS)
	$(MAKE) bonus -C ./libft
	$(COMP) $(OBJECTS) -o $@

bonus :	$(OBJECTS) 
	$(MAKE) bonus -C ./libft
	$(COMP) $(OBJECTS) -o $@

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
