NAME = 3d_project
FILES = main.c
OBJ = $(FILES:.c=.o)

FLAGS = -Wextra -Werror -Wall

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(FLAGS) $(OBJ) -o $(NAME) $(shell pkg-config --cflags --libs sdl3)

%.o : %.c
	cc $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
