# Necessities
CC := cc
CFLAGS = -Wextra -Werror -Wall -g3

# OS-specification
OS := $(shell uname)

ifeq (OS, Darwin)
	BUILD_DIR := minilibx_opengl_20191021
	CFLAGS += -Iminilibx_opengl_20191021 -framework OpenGL -framework Appkit
else ifeq (OS, Linux)
	BUILD_DIR := minilibx_linux
	CFLAGS += -I/usr/include -Iminilibx_linux -lXext -lX11 -lm -lz
else
    $(error Idk, man. Doesn't look like something I was BUILT to deal with ;3)
endif

CFLAGS += -Ilibft/includes -Llibft -lft -L$(BUILD_DIR) -lmlx
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
	$(CC) $(CFLAGS) -I$(INC_DIR) $(SRCS) -o $(NAME)

clean:
	make -C $(BUILD_DIR) clean
	make -C libft clean

fclean:
	make -C $(BUILD_DIR) fclean
	make -C libft fclean