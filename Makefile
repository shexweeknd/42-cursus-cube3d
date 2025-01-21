#MAIN VARS
CC 				= gcc 

CFLAGS 			= -g -Wall -Wextra -Werror 

NAME 			= cube

MINILIBX_URL	= https://github.com/42Paris/minilibx-linux.git

#DIRS
OBJS_DIR		= ./out
MINILIBX_DIR 	= ./minilibx-linux
MODULES_DIR		= ./modules

#FILES NAME
MAIN_FILE		= cube.c

#OBJECTS
MAIN_OBJ		= $(MAIN_FILE:%.c=$(OBJS_DIR)/%.o)

#DEPENDECIES
LIBFT_DIR		= ./libft

#LIBRARIES
MINILIBX_LIB	= -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm
LIBFT_LIB		= -L$(LIBFT_DIR) -lft
LIBS 			= $(MINILIBX_LIB) $(LIBFT_LIB)

#INCLUDES
MINILIBX_INC	= -I$(MINILIBX_DIR)/
LIBFT_INC		= -I$(LIBFT_DIR)/inc/
CUBE_INC		= -I./
INCLUDES		= $(CUBE_INC) $(MINILIBX_INC) $(LIBFT_INC)

#MAKE FUNCTIONS
define Compile
	$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
endef

define MakeLibft
	if [ -d $(LIBFT_DIR) ]; then \
		make $(1) -C $(LIBFT_DIR); \
	fi
endef

define MakeMinilibx
	if [ ! -d $(MINILIBX_DIR) ]; then \
		git clone $(MINILIBX_URL) $(MINILIBX_DIR); \
		cd $(MINILIBX_DIR) && ./configure; \
		cd ../; \
	fi

	if [ -d $(MINILIBX_DIR) ] && [ "$(1)" != "fclean" ]; then \
		make $(1) -C $(MINILIBX_DIR); \
	fi
endef

define Makebin

	$(call MakeLibft,all)
	$(call MakeMinilibx,all)

	$(CC) $(CFLAGS) $(1) $(LIBS) -o $(2)
endef

#RULES
all: $(MINILIBX_DIR) $(OBJS_DIR) | $(NAME)

#DEPENDECIES RULES

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(MINILIBX_DIR):
	$(call MakeMinilibx,all)

$(NAME) : $(MAIN_OBJ)
	$(call Makebin,$^,$@)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(call Compile,$<,$@)

clean:
	$(call MakeLibft,clean)
	$(call MakeMinilibx,clean)
	rm -rf $(OBJS_DIR)/*.o

fclean: clean
	$(call MakeLibft,fclean)
	$(call MakeMinilibx,fclean)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re