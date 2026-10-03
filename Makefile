NAME=cub3D
CC=cc

CFLAGS=-Wall -Wextra -Werror -g -Iincludes -std=gnu99 -Iminilibx-linux -Ilibft -MMD -MP

MANDATORY_SRC = src/main.c src/init.c src/free.c src/parsing1.c src/parsing2.c \
				src/parser_utils.c src/parse_texture.c src/parse_color.c \
				src/parse_map1.c src/parse_map2.c src/parse_map3.c
MANDATORY_OBJS=$(MANDATORY_SRC:.c=.o)

LIBFT=libft/libft.a
MLX=minilibx-linux/libmlx.a

all: $(NAME)

-include $(MANDATORY_OBJS:.o=.d)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MANDATORY_OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	make -C libft

$(MLX):
	make -C minilibx-linux

clean:
	rm -f $(MANDATORY_OBJS) $(MANDATORY_OBJS:.o=.d)
	make -C libft clean
	make -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
