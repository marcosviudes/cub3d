#####################################
### CONFIG
#####################################
NAME		:= cub3D
CC 			:= gcc  
CFLAGS		:= -Wall -Wextra -Werror -Wpedantic -O3 #-Wall -Wextra -Werror # -O3 -Wall -Wextra -Werror
DFLAGS		:= -g #-fsanitize=address 
LIBFT 		:= ./libft/libft.a
LIBFTSRC	:= $(wildcard libft/*.c)
LIBFTOBJ	:= $(patsubst libft/%.c, libft/%.o, $(LIBFTSRC))
RM			:= rm -rf
MKDIR		:= mkdir -p


SRCS := $(shell find src/ -type f -iname *.c)
OBJ := $(patsubst src/%.c, obj/%.o, $(SRCS))
MLX = ./mlx
INCLUDES 	:= -I includes -Imlx -Llibft -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

#####################################
### RULES
#####################################

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIRS) $(OBJ) 
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME) 

$(LIBFT): $(LIBFTOBJ)
	ar rcs $(LIBFT) $(LIBFTOBJ)
$(MLX):
	@ make -C $(MLX)
	
all: $(NAME)

libft/%.o: libft/%.c
	$(CC) -I includes -c $< -o $@

obj/%.o: src/%.c
	$(MKDIR) obj/
	$(CC) -I includes -c $< -o $@

normi:
	norminette src/*

clean:
	$(RM) libft/*.o obj/* mlx/*.o

fclean: clean
	$(RM) $(NAME) *.dSYM $(LIBFT) a.out obj
	make -C $(MLX) clean

re: fclean all

debug: fclean
	$(CC) $(DFLAGS) $(SRCS) libft/*.c -I includes -o $(NAME)
debugfile: fclean
	$(CC) $(DFLAGS) $(INCLUDES) $(SRCS) libft/*.c -I includes -o $(NAME) -D MAP_DEBUG
debugmlx:	fclean
	$(CC) $(DFLAGS) $(INCLUDES) $(SRCS) libft/*.c -I includes -o $(NAME)

.PHONY:	all clean fclean re debug

#####################################
#$(INCLUDES)
#run: $(NAME)
#	@./$(NAME) ./res/map1.cub
#runs: $(NAME)
#	@./$(NAME) ./res/map1.cub -save
#rerun: re run
#$(RM) screenshot.bmp