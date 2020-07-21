OS := $(shell uname)

NAME = cub3D

LIBFT = ./libft/libft.a
LIBFT_SRC := $(wildcard libft/*.c)
LIBFT_OBJ := $(patsubst libft/%.c, libft/%.o, $(LIBFT_SRC))

COMP = gcc #-Wall -Wextra -Werror -g3 #-Wall -Wextra -Werror # -O3 -Wall -Wextra -Werror 
INCLUDES = -Iincludes -Imlx -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
#ifeq ($(OS), Linux)
#INCLUDES = -Iincludes -I/usr/local/include/ -Llibft -lft -lm -L/usr/local/lib/ -lmlx -lXext -lX11 -lpthread
#endif

SRCS := $(shell find src/ -type f -iname *.c)
OBJ := $(patsubst src/%.c, obj/%.o, $(SRCS))

MLX = ./libs/minilibx_opengl_20191021/libmlx.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(COMP) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT): $(LIBFT_OBJ)
	ar rcs $(LIBFT) $(LIBFT_OBJ)

libft/%.o: libft/%.c
	$(COMP) -Iincludes -c $< -o $@

obj/%.o: src/%.c
	mkdir -p obj
	$(COMP) -Iincludes -c $< -o $@

run: $(NAME)
	@./$(NAME) ./res/map1.cub

runs: $(NAME)
	@./$(NAME) ./res/map1.cub -save

$(MLX):
	@ make -C ./libs/

norme:
	norminette src/*

clean:
	rm -rf libft/*.o obj/* mlx/*.o
	rm -rf screenshot.bmp

fclean: clean
	rm -rf $(NAME) *.dSYM $(LIBFT)
	make -C ./mlx clean

re: fclean all

rerun: re run