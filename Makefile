LIB_DIR				=	libft

MAKE_LIB			=	@make --no-print-directory -C

PRINTF_DIR			=	$(LIB_DIR)/printf
PRINTF_FILE			=	printf.a 	
PRINTF				=	$(PRINTF_DIR)/$(PRINTF_FILE)
CFLAGS				+=	-I$(PRINTF_DIR)/include
LIB					+=	$(PRINTF)

LIBFT_DIR			=	$(LIB_DIR)/libft
LIBFT_FILE			=	libft.a
LIBFT				=	$(LIBFT_DIR)/$(LIBFT_FILE)
CFLAGS				+=	-I$(LIBFT_DIR)/include
LIB					+=	$(LIBFT)

$(PRINTF):
	$(MAKE_LIB) $(PRINTF_DIR)

$(LIBFT):
	$(MAKE_LIB) $(LIBFT_DIR)

lib_clean:
	$(MAKE_LIB) $(PRINTF_DIR) clean
	$(MAKE_LIB) $(LIBFT_DIR) clean

lib_fclean:
	$(MAKE_LIB) $(PRINTF_DIR) fclean
	$(MAKE_LIB) $(LIBFT_DIR) fclean

lib_re:
	$(MAKE_LIB) $(PRINTF_DIR) re
	$(MAKE_LIB) $(LIBFT_DIR) re
