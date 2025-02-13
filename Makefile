CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFT = library/libft/

LIBFT_NAME = library/libft/libft.a

FILES = moves/push.c moves/rotate.c moves/swap.c \
	sort/sort_three.c sort/sort_four.c sort/sort_five.c \
	sort/sort_stack.c help_functions.c parsing.c parsing2.c main.c

F_OBJ = $(FILES:.c=.o)

$(NAME): $(FILES)
	make -C $(LIBFT)
	cc $(CFLAGS)  $(FILES) $(LIBFT_NAME) -o	$(NAME)

all : $(NAME)

clean :
		make clean -C $(LIBFT)
		rm -f $(F_OBJ)
fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : clean fclean