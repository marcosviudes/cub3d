#####################################
### CONFIG
#####################################
NAME		:= cub3D
CC 			:= gcc  
CFLAGS		:= #-Wall -Wextra -Werror -g3 #-Wall -Wextra -Werror # -O3 -Wall -Wextra -Werror
LIBFT 		:= ./libft/libft.a
LIBFTSRC	:= $(wildcard libft/*.c)
LIBFTOBJ	:= $(patsubst libft/%.c, libft/%.o, $(LIBFTSRC))
RM			:= rm -rf
MKDIR		:= mkdir -p

SRCS := $(shell find src/ -type f -iname *.c)
OBJ := $(patsubst src/%.c, obj/%.o, $(SRCS))
MLX = ./libs/minilibx_opengl_20191021/libmlx.a
INCLUDES 	:= #-Iincludes -Imlx -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

ifdef DEBUG
	CFLAGS +=-g
endif
#####################################
### RULES
#####################################

$(NAME): $(LIBFT) $(OBJ)#$(MLX) 
	$(CC) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME) $(CFLAGS)

$(LIBFT): $(LIBFTOBJ)
	ar rcs $(LIBFT) $(LIBFTOBJ)
$(MLX):
	@ make -C ./libs/minilibx_mms_20200219
all: $(NAME)

libft/%.o: libft/%.c
	$(CC) -I includes -c $< -o $@

obj/%.o: src/%.c
	$(MKDIR) obj
	$(CC) -I includes -c $< -o $@

normi:
	norminette src/*

clean:
	$(RM) libft/*.o obj/* mlx/*.o

fclean: clean
	$(RM) $(NAME) *.dSYM $(LIBFT)
	make -C ./mlx clean

re: fclean all

.PHONY:	all clean fclean re debug

#####################################

#run: $(NAME)
#	@./$(NAME) ./res/map1.cub
#runs: $(NAME)
#	@./$(NAME) ./res/map1.cub -save
#rerun: re run
#$(RM) screenshot.bmp