# Necessities
CC := cc
CFLAGS = -Wextra -Werror -Wall -g3

# OS-specification
OS := $(shell uname)

Dar = Darwin

Lin = Linux

ifeq (${OS}, ${Dar})
	BUILD_DIR := minilibx_opengl_20191021
	MLX := mlx
	CFLAGS += -I$(BUILD_DIR) -framework OpenGL -framework Appkit
else ifeq (${OS}, ${Lin})
	BUILD_DIR := mlx_linux
	MLX := mlx_Linux
	CFLAGS += -L$(BUILD_DIR) -I$(BUILD_DIR) -l$(MLX) -L/usr/lib -lXext -lX11 -lm -lz -Llibft -Ilibft/includes -lft
else
    $(error Idk, man. Doesn't look like something I was BUILT to deal with ;3)
endif

# PROJECT
NAME := so_long

SRC := main.c
SRC_DIR := srcs
SRCS := $(addprefix srcs/, $(SRC))

INC := so_long.h
INC_DIR := includes
INCLUDE := $(addprefix $(INC_DIR)/, $(INC))

all: $(NAME)

$(NAME): $(SRCS) $(INCLUDE)
	make -C $(BUILD_DIR)
	make -C libft 
	$(CC) -o $(NAME) -I$(INC_DIR) $(SRCS) $(CFLAGS)  

clean:
	make -C $(BUILD_DIR) clean
	make -C libft clean

fclean:
	make -C $(BUILD_DIR) clean
	rm -rf $(BUILD_DIR)/lib$(MLX).a
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all