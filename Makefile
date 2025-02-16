CC = cc
CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap

LIBFT = libft/

LIBFT_NAME = libft/libft.a

FILES = moves/push.c moves/rotate.c moves/swap.c \
	sort/sort_three.c sort/sort_four.c sort/sort_five.c \
	sort/sort_stack.c help_functions.c parsing.c parsing_help.c main.c \

F_OBJ = $(FILES:.c=.o)

all : $(LIBFT_NAME) $(NAME)

$(NAME): $(F_OBJ)
	$(CC) $(CFLAGS)  $(F_OBJ) $(LIBFT_NAME) -o	$@

$(LIBFT_NAME): $(F_OBJ)
	make -C $(LIBFT)

clean :
		make clean -C $(LIBFT)
		rm -f $(F_OBJ)
fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean