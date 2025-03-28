	NAME	= fractol


$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

all:
	cc -g3 fractol.c utils/init.c librarys/minilibx-linux/libmlx_Linux.a librarys/42_Libft/libft.a -Ilibrarys/minilibx-linux -Ilibrarys/42_Libft -Llibrarys/minilibx-linux -L/usr/lib -lXext -lX11 -lm -lz
