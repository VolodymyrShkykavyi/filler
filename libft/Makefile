NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
OBJECT_DIR = objects
INCLUDES = includes
OBJ = $(addprefix $(OBJECT_DIR)/, $(SRC:.c=.o))
SRC = ft_memalloc.c ft_putstr_fd.c ft_strncat.c ft_memccpy.c ft_putwchar.c ft_strncmp.c \
	ft_atoi.c ft_memchr.c ft_putwstr.c ft_strncpy.c ft_bzero.c ft_memcmp.c ft_str_tolower.c \
	ft_strnequ.c ft_chrin_str.c ft_memcpy.c ft_str_toupper.c ft_strnew.c ft_isalnum.c \
	ft_memdel.c ft_strcat.c ft_strnew_tolower.c ft_isalpha.c ft_memmove.c ft_strchr.c \
	ft_strnew_toupper.c ft_isascii.c ft_memset.c ft_strclr.c ft_strnstr.c ft_isdigit.c \
	ft_printarr.c ft_strcmp.c ft_strrchr.c ft_isprint.c ft_strcpy.c ft_strsplit.c \
	ft_isspace.c ft_putchar.c ft_strdel.c ft_strstr.c ft_itoa.c ft_putchar_fd.c \
	ft_strdup.c ft_strsub.c ft_itoa_base.c ft_putendl.c ft_strequ.c ft_strtrim.c \
	ft_lstadd.c ft_putendl_fd.c ft_striter.c ft_tolower.c ft_lstdel.c ft_putnbr.c \
	ft_striteri.c ft_toupper.c ft_lstdelone.c ft_putnbr_fd.c ft_strjoin.c ft_uitoa_base.c \
	ft_lstiter.c ft_putnchar.c ft_strlcat.c ft_utf8_bytelen.c ft_lstmap.c ft_putnstr.c \
	ft_strlen.c ft_wstrsize.c ft_lstnew.c ft_putnwstr.c ft_strmap.c get_next_line.c \
	ft_lstsize.c ft_putstr.c ft_strmapi.c ft_free_2arr.c \
	$(addprefix ft_printf/, ft_printf_cast_unum.c ft_specinfo_init.c specificator_manager.c \
	ft_printf.c ft_printf_getcolor.c print_manager.c $(addprefix formats/, format_b.c format_c.c \
	format_d_i.c format_n.c format_o.c format_p.c format_s.c format_u.c format_x.c))

all: $(NAME)
$(NAME) : $(OBJECT_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@tput el && tput cnorm
	@echo "\033[0;32mlib compiled\033[0m"
$(OBJECT_DIR):
	@mkdir -p $(OBJECT_DIR)
	@mkdir -p $(OBJECT_DIR)/ft_printf
	@mkdir -p $(OBJECT_DIR)/ft_printf/formats
$(OBJECT_DIR)/%.o: %.c
	@echo "\033[33mcompiling...\ntarget: $@"
	@tput civis
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INCLUDES)
	@tput cuu 1 && tput el && tput cuu 1
clean:
	@rm -rf $(OBJECT_DIR)
	@echo "\033[32mcleaned\033[0m"
fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mlib deleted\033[0m"
re:
	@make fclean
	@make	
