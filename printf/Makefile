NAME = printf.a

HDIR = include/private
SDIR = srcs
ODIR = objs

SRCS := $(wildcard $(SDIR)/*.c)
OBJS := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HDIR) -fvisibility=hidden

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

$(ODIR)/%.o: $(SDIR)/%.c | $(DIRS)
	@$(CC) $(CFLAGS) -c -o $@ $< && echo -n "$(BRIGHT_GREEN).$(RESET)"

bonus : all

clean:
	@rm -rf objs

fclean: clean
	@rm -rf $(BINARY) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
