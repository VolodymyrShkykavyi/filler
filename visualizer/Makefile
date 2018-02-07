NAME = vshkykav.filler
CC = gcc
FLAGS = -Wall -Werror -Wextra
OBJECT_DIR = objects
OBJ = $(addprefix $(OBJECT_DIR)/, $(SRC:src/%.c=%.o))
SRC = $(addprefix src/, main.c read.c get_player.c algorithm.c alg_additional.c)
INCLUDES = src/filler.h

all: $(NAME)
$(NAME) : $(OBJECT_DIR) $(OBJ)
	$(MAKE) -C libft
	$(CC) $(OBJ) -o $(NAME) -I $(INCLUDES) -L./libft -lft
$(OBJECT_DIR):
	@mkdir -p $(OBJECT_DIR)	
$(OBJECT_DIR)/%.o: src/%.c
	$(CC) $(FLAGS) -o $@ -c $< 
clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ)
	rm -rf  $(OBJECT_DIR)/
fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)
re: fclean
	$(MAKE) re -C libft
	make
compile:
	make
	rm -f players/$(NAME)
	mv $(NAME) players/$(NAME)
	gcc $(FLAGS) visualizer/main.c -o visualize -L./libft -lft
run:
	./filler_vm -p1 players/$(NAME) -p2 players/abanlin.filler -f maps/map00
