HDIR				=	include
SDIR				=	srcs
ODIR				=	objs

NAME 				=	libft.a
CC 					=	gcc
CFLAGS 				=	-Wall -Wextra -Werror -Iinclude/private

VPATH				=	$(SDIR):$(SDIR)/conversion:$(SDIR)/list:$(SDIR)/memory:$(SDIR)/output:$(SDIR)/string

SRCS				:=	atoi.c itoa.c tolower.c toupper.c \
		lstadd_back.c lstclear.c lstiter.c lstmap.c lstsize.c lstadd_front.c \
		lstdelone.c lstlast.c lstnew.c bzero.c calloc.c memchr.c memcmp.c  \
		memcpy.c memmove.c memset.c gnl.c gnl_utils.c putchar_fd.c putendl_fd.c \
		putnbr_fd.c putstr_fd.c isalnum.c isdigit.c strchr.c striteri.c \
		strlcpy.c strncmp.c strtrim.c isalpha.c isprint.c strcmp.c strjoin.c \
		strlen.c  strnstr.c substr.c isascii.c split.c strdup.c strlcat.c strmapi.c \
		strrchr.c atod.c


OBJS := $(patsubst %.c,$(ODIR)/%.o,$(SRCS))

BRIGHT_GREEN = $(shell printf "\033[92m")
GREEN = $(shell printf "\033[32m")
RESET = $(shell printf "\033[0m")
YELLOW = $(shell printf "\033[33m")

all: $(NAME)

$(ODIR):
	@mkdir -p $@

welcome: $(ODIR)
	@echo -n "$(YELLOW)Building libft: $(RESET)"

$(ODIR)/%.o: %.c | welcome
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

