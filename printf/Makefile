NAME = printf.a

HDIR = include/private
SDIR = srcs
ODIR = objs

SRCS := $(wildcard $(SDIR)/*.c)
OBJS := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HDIR) -fvisibility=hidden

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus : all

clean:
	@rm -rf objs

fclean: clean
	@rm -rf $(BINARY) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
