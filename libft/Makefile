HDIR				=	include
SDIR				=	srcs
ODIR				=	objs

NAME 				=	libft.a
CC 					=	gcc
CFLAGS 				=	-Wall -Wextra -Werror -Iinclude/private

DIRS				:=	$(ODIR) $(ODIR)/conversion $(ODIR)/list $(ODIR)/memory $(ODIR)/output $(ODIR)/string
VPATH				=	$(SDIR):$(SDIR)/conversion:$(SDIR)/list:$(SDIR)/memory:$(SDIR)/output:$(SDIR)/string
SRCS 				:=	$(wildcard $(SDIR)/*/*.c)
OBJS				:=	$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))

BRIGHT_GREEN = \033[92m
GREEN = \033[32m
RESET = \033[0m
YELLOW = \033[33m

all: $(NAME)

welcome:
	@echo -n "$(YELLOW)Building libft: $(RESET)"

$(DIRS): | welcome
	@mkdir -p $@

$(ODIR)/%.o: $(SDIR)/%.c | $(DIRS)
	@$(CC) $(CFLAGS) -c -o $@ $< && echo -n "$(BRIGHT_GREEN).$(RESET)"

$(NAME): $(OBJS)
	@echo
	@ar rcs $@ $^ && echo "$(GREEN)libft created.$(RESET)"
	@echo

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

