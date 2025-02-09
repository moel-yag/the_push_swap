CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC = moves/push.c moves/rotate.c moves/swap.c \
	sort/sort_three.c sort/sort_four.c sort/sort_five.c \
	sort/sort_stack.c main.c

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS)
