#####################################
### CONFIG
#####################################
NAME	:= cub3D
C		:= gcc
CFLAGS	:= #-Wall -Wextra -Werror# -O3 -Wall -Wextra -Werror -I
MKDIR	:= mkdir -p
LIBFT	:= libft/
OBJ		:= obj
SRCS	:= src
INCL	:= -L $(LIBFT)
RM		:= rm -rf

ALLCS		:= $(shell find src/ -type f -iname *.c)
ALLOS		:= $(shell find obj/ -type f -iname *.o)
ALLCSOBJS	:= $(patsubst %.c,%.o,$(ALLCS))
#ALLCSOBJS	:= $(foreach F,$(ALLCS),$(call C2O,$(F)))
DIRS		:= $(shell find $(SRCS) -type d)
OBJ_DIRS	:= $(patsubst $(SRCS)%, $(OBJ)%, $(DIRS))

#####################################
### MACROS
#####################################
#define COMPILE
#$(2) : $(3)
#	$(1) -c -o $(2)$(3)$(4)
#endef
#
#define C2O
#$(patsubst %.c,%.o,patsubst($(SRCS)%, $(OBJ)%, $(1)))
#endef

${NAME}:	$(OBJ_DIRS) $(ALLCSOBJS)
		$(C) -o $(NAME) $(ALLOS) $(INCL) -I includes/
		# $(ALLCSOBJS)
$(OBJ_DIRS):
	$(MKDIR)$(OBJ_DIRS)
#$(foreach F,$(ALLCS),$(call COMPILE,$(C),$(call C2O,$(F)),$(F),$(CFLAGS)))
%.o: %.c
	$(C) -o $(patsubst $(SRCS)%,$(OBJ)%,$@) -c $^ $(CFLAGS) 

all:		${NAME}
			
clean:	
			rm -rf $(OBJ)/*
fclean:	clean 
			rm -f ${NAME}
re:		fclean all
debug:		$(OBJ_DIRS) $(ALLCSOBJS)
		$(C) -o -g $(NAME) $(ALLCSOBJS)
.PHONY:	all clean fclean re 