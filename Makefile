SRCS = ./src/so_long_main.c ./src/utils.c ./src/utils_2.c ./src/map_all_func.c ./src/key_hook.c
SRCBS = ./srcb/main_bonus.c ./srcb/utils_bonus.c ./srcb/utils_2_bonus.c ./srcb/map_all_func_bonus.c ./srcb/key_hook_bonus.c \
	./srcb/render_bonus.c  ./srcb/enemy_render_bonus.c 	./srcb/setting_index_all.c ./srcb/add_photo_all_bonus.c
NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LFLAGS = -framework AppKit -framework OpenGL -L./mlx_lib -lmlx
MLX = ./mlx_lib/libmlx.a
FT_PRINTF = ./ft_printf/libftprintf.a
GET_NEXT_LINE = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
RM = rm -rf
LIBC = ar -rcs

all: $(MLX) ${NAME}

$(NAME): $(SRCS) $(MLX) $(FT_PRINTF) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)
	@echo "<3 :3 uWu <3 :3"

bonus : $(SRCBS) $(MLX) $(FT_PRINTF) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCBS) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)
	@echo "<3 :3 uWu <3 :3"

$(MLX) :
	@make -C ./mlx_lib

$(FT_PRINTF) :
	@make -C ./ft_printf

clean:

fclean: clean
	@rm -rf $(NAME)
	@make clean -C ./mlx_lib
	@make fclean -C ./ft_printf

re: fclean all

.PHONY: all bonus clean fclean re .c.o



