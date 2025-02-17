CC = cc
CFLAGS = -g -Wall -Wextra -Werror

NAME = push_swap
B_NAME = checker

LIBFT = libft/

LIBFT_NAME = libft/libft.a

FILES = moves/push.c moves/rotate.c moves/swap.c \
	sort/sort_three.c sort/sort_four.c sort/sort_five.c \
	sort/sort_stack.c help_functions.c parsing.c parsing_help.c main.c \

BONUS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	bonus/checker.c help_functions.c parsing_help.c parsing.c \
	bonus/push_bonus.c bonus/rotate_bonus.c bonus/swap_bonus.c

F_OBJ = $(FILES:.c=.o)

B_OBJ = $(BONUS:.c=.o)

all : $(LIBFT_NAME) $(NAME)

$(NAME): $(F_OBJ)
	$(CC) $(CFLAGS) $(F_OBJ) $(LIBFT_NAME) -o	$@

bonus : $(B_NAME)

$(B_NAME): $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) $(LIBFT_NAME) -o	$@

$(LIBFT_NAME): $(F_OBJ) $(B_OBJ)
	make -C $(LIBFT)

clean :
		make clean -C $(LIBFT)
		rm -f $(F_OBJ) $(B_OBJ)
fclean : clean
		rm -f $(NAME) $(B_NAME)

re : fclean all

.PHONY : all bonus clean fclean re