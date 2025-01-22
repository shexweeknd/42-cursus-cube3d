#COLORS
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
NC=\033[0m

#MAIN VARS
CC 				= cc 

CFLAGS 			= -g -Wall -Wextra -Werror 

NAME 			= cube

MINILIBX_URL	= https://github.com/42Paris/minilibx-linux.git

#DIRS
OBJS_DIR		= ./out
MINILIBX_DIR 	= ./mlx
MODULES_DIR		= ./modules

#MODULES_DIR
SCREEN_DIR		= $(MODULES_DIR)/screen

#FILES NAME
MAIN_FILE		= cube.c

#OBJECTS
MAIN_OBJ		= $(MAIN_FILE:%.c=$(OBJS_DIR)/%.o)

#DEPENDECIES
LIBFT_DIR		= ./libft

#LIBRARIES INCLUDES
MINILIBX_INC	= -I$(MINILIBX_DIR)/
LIBFT_INC		= -I$(LIBFT_DIR)/inc/

#LIBRARIES
MINILIBX_LIB	= -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm
LIBFT_LIB		= -L$(LIBFT_DIR) -lft
SCREEN_LIB		= -L$(SCREEN_DIR) -lscreen
LIBS 			= $(MINILIBX_LIB) $(LIBFT_LIB) $(SCREEN_LIB)

#MODULES INCLUDES
SCREEN_INC		= -I$(SCREEN_DIR)/inc/

#INCLUDES
CUBE_INC		= -I./
INCLUDES		= $(CUBE_INC) $(MINILIBX_INC) $(LIBFT_INC) $(SCREEN_INC)

#MAKE FUNCTIONS
define Compile
	$(CC) $(CFLAGS) -c $(1) -o $(2)
endef

define MakeLibft
	@if [ -d $(LIBFT_DIR) ]; then \
		make $(1) -C $(LIBFT_DIR); \
		echo "$(GREEN)libft compiled$(NC)"; \
	fi
endef

define MakeMinilibx
	@if [ ! -d $(MINILIBX_DIR) ]; then \
		git clone $(MINILIBX_URL) $(MINILIBX_DIR) \; \
		echo "$(GREEN)minilibx-linux cloned$(NC)"; \
	fi

	@if [ -d $(MINILIBX_DIR) ] && [ "$(1)" != "fclean" ]; then \
		make $(1) -C $(MINILIBX_DIR) -s; \
		echo "$(GREEN)minilibx-linux compiled$(NC)"; \
	fi
endef

define MakeModules
	@if [ -d $(1) ]; then \
		make $(2) -C $(1); \
		echo "$(GREEN)$(1) compiled$(NC)"; \
	fi
endef

define Makebin
	$(call MakeLibft,all)
	$(call MakeMinilibx,all)
	
	$(call MakeModules,$(SCREEN_DIR),all)

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
	$(call MakeModules,$(SCREEN_DIR),clean)
	rm -rf $(OBJS_DIR)/*.o

fclean: clean
	$(call MakeLibft,fclean)
	$(call MakeMinilibx,fclean)
	$(call MakeModules,$(SCREEN_DIR),fclean)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re