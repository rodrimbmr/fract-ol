NAME = fractol

SRC = utils/atodbl.c utils/events.c utils/init.c utils/math_utils.c utils/render.c fractol.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Iminilibx-linux -Isrc -g3 -Ofast -march=native -funroll-loops -flto

MLX_DIR = librarys/minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

$(NAME): $(OBJ)
	@cd librarys/42_Libft && $(MAKE) > /dev/null
	@cd $(MLX_DIR) && $(MAKE) > /dev/null 2>/dev/null
	@$(CC) $(CFLAGS) $(OBJ) -L ./librarys/42_Libft -lft -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)
	@echo "Compilation complete!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@cd librarys/42_Libft && $(MAKE) clean > /dev/null
	@cd $(MLX_DIR) && $(MAKE) clean > /dev/null
	@rm -f $(OBJ)
	@echo "Clean complete!"

fclean: clean
	@cd librarys/42_Libft && $(MAKE) fclean > /dev/null
	@rm -f $(NAME)
	@echo "Full clean complete!"

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re
