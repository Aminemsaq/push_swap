NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Werror -Wextra
RM      = rm -rf

INCLUDE = push_swap.h

SRC     = main.c utils_join.c utils_parsing.c utils_convert_int.c \
          init_push_swap.c utils_stack.c push_instructions.c swap_instructions.c \
          rotate_instructions.c reverse_rotate_instructions.c utils_algo.c \
          utils_indexing.c utils_libft.c utils_libft2.c utils_libft3.c utils_algo2.c utils_libft4.c \

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all