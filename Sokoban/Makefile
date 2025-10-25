# Makefile

NAME = Sokoban

SRCS = main.c \
	print_tab.c \
	init_tab.c \
	randomizer.c \

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all