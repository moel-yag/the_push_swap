CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFT = library/libft/

LIBFT_NAME = library/libft/libft.a

FILES = moves/push.c moves/rotate.c moves/swap.c \
	sort/sort_three.c sort/sort_four.c sort/sort_five.c \
	sort/sort_stack.c main.c

FILES_O = $(FILES:.c=.o)

$(NAME): $(FILES_O)
	make -C $(LIBFT)
	cc $(CFLAGS)  $? $(LIBFT_NAME) -O $@

all : $(NAME)

clean :
		make clean -C $(LIBFT)
		rm -f $(FILES_O)
fclean : clean
		make fclean -C $(LIBFT)
		rm -f $(NAME)

re : fclean all