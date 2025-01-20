NAME = printf.a

HDIR = include/private
SDIR = srcs
ODIR = objs

SRCS = ft_parsers.c ft_printf_utils.c parse_specifier.c pf_hex.c pf_pointer.c pf_unsigned.c \
		ft_printf.c libft.c pf_char.c pf_integer.c pf_string.c
OBJS := $(patsubst %.c, $(ODIR)/%.o, $(SRCS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HDIR) -fvisibility=hidden

VPATH = srcs

DIRS = $(ODIR)

BRIGHT_GREEN = \033[92m
GREEN = \033[32m
RESET = \033[0m
YELLOW = \033[33m

all: $(NAME)

welcome:
	@echo -n "$(YELLOW)Building printf: $(RESET)"

$(DIRS): |welcome
	@mkdir -p $@

$(NAME): $(OBJS)
	@echo
	@ar rcs $@ $^ && echo "$(GREEN)printf created.$(RESET)"
	@echo

$(ODIR)/%.o: %.c | $(DIRS)
	@$(CC) $(CFLAGS) -c -o $@ $< && echo -n "$(BRIGHT_GREEN).$(RESET)"

bonus : all

clean:
	@rm -rf objs

fclean: clean
	@rm -rf $(BINARY) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
