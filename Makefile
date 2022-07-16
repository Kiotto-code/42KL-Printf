NAME = libftprint.a
# INCLUDE = libftprint.h
SRCS =
OBJS = $(SRCS:.c=.o)
LOBJS = $(wildcard libft/*.o)

CC = gcc
CFLAGS = -Wall - Werror -Wextra
RM = rm -f 

all: $(NAME)

$(NAME): $(OBJS) libft
	ar rcs $(NAME) $(OBJS) $(LOBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all