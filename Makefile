NAME = cub3D 
CC = cc 

CFLAGS = -Wall -Wextra -Werror -g -Iincludes -std=gnu99 -Iminilibx-linux/minilibx-linux


MANDATORY_SRC = src/main.c src/init.c src/free.c \
			  src/parser_utils1.c src/parsing.c src/parse_color.c \
			  src/parse_texture.c src/parse_map.c \

INCLUDE = includes/cub3d.h libft/libft.h

MANDATORY_OBJS = $(MANDATORY_SRC:.c=.o)

LIBFT = ../libft/libft.a

MLX = ../minilibx-linux/libmlx.a

all: $(LIBFT) $(MLX) $(NAME) 

$(MLX):
	$(MAKE) -C minilibx-linux

$(LIBFT):
	$(MAKE) -C libft 

$(NAME): $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(MANDATORY_OBJS) \
		$(LIBFT) $(MLX) -lXext -lX11 -lm -lz

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@  

clean:
	rm -f $(MANDATORY_OBJS) 
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C minilibx-linux clean
	$(MAKE) -C libft

re: fclean all

.PHONY: all clean fclean re 
