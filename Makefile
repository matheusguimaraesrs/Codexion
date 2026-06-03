CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = codexion
SRCS = main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "codexion compiled"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "Object files cleaned"

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@echo "All clean!"

re: fclean all

.PHONY: all clean fclean re
