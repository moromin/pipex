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

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $(<:.c=.o)

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus $(NAME)
