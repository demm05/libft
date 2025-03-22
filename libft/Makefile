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

BRIGHT_GREEN = "92m"
GREEN = "32m"
YELLOW = "33m"

all: $(NAME)

$(ODIR):
	@mkdir -p $(ODIR)

$(NAME): $(ODIR)
	@printf "\033[33mBuilding libft:\033[0m"
	@$(MAKE) -s build_objects
	@ar rcs $(NAME) $(OBJS)
	@printf "\r\033[K\033[32mLibft was built\033[0m\n"

build_objects: $(OBJS)

$(ODIR)/%.o: %.c
	@printf "\r\033[$(YELLOW)$(CC) $(CFLAGS) -c -o $@ $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
