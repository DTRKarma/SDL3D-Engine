NAME = 3d_project
FILES = main.c
OBJS = $(FILES:.c=.o)

CC = cc
CFLAGS = -Wextra -Werror -Wall -03 'pkg-config --cflags sdl3' -I include
LIBS = 'pkg-config --cflags sdl3' -lm

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIBS)

%.o : %.c
	cc $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
