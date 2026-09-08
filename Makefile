NAME=cub3D # Name of the final executable
CC=cc # C compiler

# Compiler options and header directories
CFLAGS=-Wall -Wextra -Werror -g -Iincludes -std=gnu99 # -Iminilibx-linux -Ilibft -MMD -MP

# Source files for the project
MANDATORY_SRC=main.c

 # Convert .c files into .o files
MANDATORY_OBJS=$(MANDATORY_SRC:.c=.o)

-include $(MANDATORY_OBJS:.o=.d)

# Path to Libft library
LIBFT=libft/libft.a

# Path to MiniLibX library
# MLX=minilibx-linux/libmlx.a

all: $(NAME) # Default target: build cub3D

%.o: %.c  # Rule: create a .o file from a .c file
	$(CC) $(CFLAGS) -c $< -o $@  # Compile the source file into an object file

$(NAME): $(MANDATORY_OBJS) $(LIBFT) # cub3D needs our .o + Libft + MiniLibX
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(LIBFT) -o $(NAME) 

$(LIBFT): # If libft.a doesn't exist, build Libft
	make -C libft # Run Libft's Makefile, C refers to change dir

clean:     # Remove compiled object files
	rm -f $(MANDATORY_OBJS) $(MANDATORY_OBJS:.o=.d)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re  # These are commands, not real files