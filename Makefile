# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhuang2 <hhuang2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/05 23:51:45 by hhuang2           #+#    #+#              #
#    Updated: 2026/09/06 00:31:17 by hhuang2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC = main.c init.c free.c parse_map.c parse_texture.c parsing.c 
OBJ = $(SRC:.c=.o)
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I. -I$(LIBFT_PATH)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
		
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJ)
	
fclean:
	+(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(OBJ)
	rm -f $(NAME)

re:
	+(MAKE) fclean
	+(NAME) all

.PHONY: all clean fclean re