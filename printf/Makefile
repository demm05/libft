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

BRIGHT_GREEN = "92m"
GREEN = "32m"
YELLOW = "33m"

all: $(NAME)

$(ODIR):
	@mkdir -p $(ODIR)

$(NAME): $(ODIR)
	@printf "\033[33mBuilding printf:\033[0m"
	@$(MAKE) -s build_objects
	@ar rcs $(NAME) $(OBJS)
	@printf "\r\033[K\033[32mPrintf was built\033[0m\n"

build_objects: $(OBJS)

$(ODIR)/%.o: %.c
	@printf "\r\033[$(YELLOW)$(CC) $(CFLAGS) -c -o $@ $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

bonus : all

clean:
	@rm -rf objs

fclean: clean
	@rm -rf $(BINARY) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
