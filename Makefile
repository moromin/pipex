NAME		= pipex
SRC			=	main.c \
				free_array.c
SRCDIR		= sources
INCDIR		= includes
SRCS		= $(addprefix $(SRCDIR)/, $(SRC))
OBJS		= $(SRCS:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIBFT_PATH	= ./libft/
GNL_PATH	= ./gnl/

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	make -C $(GNL_PATH)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -L$(GNL_PATH) -lgnl -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $(<:.c=.o)

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(GNL_PATH)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(GNL_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus $(NAME)
