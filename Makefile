#COLORS
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
GRAY=\033[0;37m
ORANGE=\033[0;33m
NC=\033[0m

SILENT = 

#DIRS
MODULES_DIR		= ./modules
OBJS_DIR		= ./out

#MODULES_DIR
LIBFT_DIR		= $(MODULES_DIR)/libft
MINILIBX_DIR 	= $(MODULES_DIR)/minilibx-linux
LIBSCREEN_DIR	= $(MODULES_DIR)/screen
LIBERRORS_DIR	= $(MODULES_DIR)/errors
LIBMAPS_DIR		= $(MODULES_DIR)/maps

ARCHIVES 		= $(LIBFT_DIR)/libft.a \
					$(LIBSCREEN_DIR)/libscreen.a \
					$(LIBERRORS_DIR)/liberrors.a \
					$(LIBMAPS_DIR)/libmaps.a \

OUT_LIB     	= $(MODULES_DIR)/libmodules.a

#MAIN VARS
CC 				= gcc 

CFLAGS 			= -g -Wall -Wextra -Werror 

NAME 			= cube

MAP 			=

MINILIBX_URL	= https://github.com/42Paris/minilibx-linux.git

#FILES NAME
MAIN_FILE		= cube.c

#OBJECTS
MAIN_OBJ		= $(MAIN_FILE:%.c=$(OBJS_DIR)/%.o)

#LIBRARIES
X11_LIB			= -lX11 -lXext -lm

#LIBRARIES INCLUDES
CUBE_INC		= -I./
MINILIBX_INC	= -I$(MINILIBX_DIR)/
LIBFT_INC		= -I$(LIBFT_DIR)/inc/
LIBSCREEN_INC	= -I$(LIBSCREEN_DIR)/inc/
LIBERRORS_INC	= -I$(LIBERRORS_DIR)/inc/
LIBMAPS_INC		= -I$(LIBMAPS_DIR)/inc/

INCLUDES		= $(MINILIBX_INC) $(LIBFT_INC) $(LIBSCREEN_INC) $(LIBERRORS_INC) $(LIBMAPS_INC) $(CUBE_INC)

#MAKE FUNCTIONS
# $(call Printprogress,OPERATION,LIBRARY,COLOR)
define Printprogress
	i=1; while [ $$i -le 100 ]; do \
        printf "\r$(GRAY) $(1) de $(2) %d%% $(NC)" $$i; \
        sleep 0.00009; \
       	i=$$((i + 1)); \
    done; \
    printf "\r$(3)⚬ $(1) de $(2) 100%% ✔$(NC)\n"
endef

define Compile
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
	@echo "	↳ $(2) compiled"
endef

define MakeMinilibx
	@if [ ! -d $(MINILIBX_DIR) ]; then \
		git clone $(MINILIBX_URL) $(MINILIBX_DIR); \
		cd $(MINILIBX_DIR) && ./configure; \
		cd ../; \
	fi

	@if [ -d $(MINILIBX_DIR) ] && [ "$(1)" != "fclean" ]; then \
		make $(1) -C $(MINILIBX_DIR) 2>&1 | grep "[info]" > /dev/null; \
	fi

	@if [ "$(1)" = "all" ]; then \
		$(call Printprogress,Compilation,$(MINILIBX_DIR),$(GREEN)); \
	elif [ "$(1)" = "clean" ]; then \
		$(call Printprogress,Cleaning,$(MINILIBX_DIR),$(YELLOW)); \
	fi
endef

define MakeModule
	@if [ -d $(1) ]; then \
		make $(2) -C $(1) -s; \
	fi

	@if [ "$(2)" = "all" ]; then \
		$(call Printprogress,Compilation,$(1),$(GREEN)); \
	elif [ "$(2)" = "clean" ]; then \
		$(call Printprogress,Cleaning,$(1),$(YELLOW)); \
	elif [ "$(2)" = "fclean" ]; then \
		$(call Printprogress,Total cleaning,$(1),$(RED)); \
	fi
endef

define CombineLibs
	@echo "$(YELLOW)⚬ Combining libraries into $(OUT_LIB)...$(NC)"
	@for lib in $(ARCHIVES); do \
		echo "	↳ Extracting $$lib..."; \
		ar x $$lib --output=$(OBJS_DIR); \
	done
	@cp $(MINILIBX_DIR)/libmlx.a $(OUT_LIB)
	@ar rcs $(OUT_LIB) $(OBJS_DIR)/*.o
	@ranlib $(OUT_LIB)
	@echo "$(YELLOW)⚬ $(OUT_LIB) module packed successfully ✔$(NC)"
endef

define Makebin
	$(call MakeMinilibx,all)
	$(call MakeModule,$(LIBFT_DIR),all)
	$(call MakeModule,$(LIBSCREEN_DIR),all)
	$(call MakeModule,$(LIBERRORS_DIR),all)
	$(call MakeModule,$(LIBMAPS_DIR),all)

	$(call CombineLibs)
	@$(CC) $(CFLAGS) $(1) -L./$(MODULES_DIR) -lmodules $(X11_LIB) -o $(2)
	@echo "$(GREEN)THE EXECUTABLE: $(2) is ready $(NC)"
endef

#RULES
all: $(MINILIBX_DIR) $(OBJS_DIR) | $(NAME)

#DEPENDECIES
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(MINILIBX_DIR):
	$(call MakeMinilibx,all)\

$(NAME) : $(MAIN_OBJ)
	$(call Makebin,$^,$@)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@echo "$(BLUE)COMPILING OBJS FILES: $(NC)"
	$(call Compile,$<,$@)

clean:
	$(call MakeMinilibx,clean)
	$(call MakeModule,$(LIBFT_DIR),clean)
	$(call MakeModule,$(LIBSCREEN_DIR),clean)
	$(call MakeModule,$(LIBERRORS_DIR),clean)
	$(call MakeModule,$(LIBMAPS_DIR),clean)
	@rm -rf $(OBJS_DIR)/*.o

fclean: clean
	$(call MakeMinilibx,fclean)
	$(call MakeModule,$(LIBFT_DIR),fclean)
	$(call MakeModule,$(LIBSCREEN_DIR),fclean)
	$(call MakeModule,$(LIBERRORS_DIR),fclean)
	$(call MakeModule,$(LIBMAPS_DIR),fclean)
	@rm -rf $(NAME) $(OUT_LIB)

re: fclean all

run: all
	@echo "$(ORANGE)🏁 EXECUTING ./$(NAME) 🏁$(NC)"
	@./$(NAME)

valrun: all
	@echo "$(ORANGE)🏁 EXECUTING ./$(NAME) $(RED) WITH VALGRIND🏁$(NC)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(MAP)

rerun: re run

# GIT
github:
	@$(call Printprogress,Adding github remote,Cube3D,$(YELLOW))
	-@git remote add origin https://github.com/shexweeknd/42-cursus-cube3d.git
	@git push --set-upstream origin
	@$(call Printprogress,Pushing to github remote,Cube3D,$(GREEN))

vogsphere:
	@$(call Printprogress,Adding vogsphere remote,Cube3D,$(YELLOW))
	-@git remote add vogsphere git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-0d67723d-799d-49a4-b427-4fdde4d58fca-6261471-hramaros
	@git push --set-upstream vogsphere
	@$(call Printprogress,Pushing to vogsphere remote,Cube3D,$(GREEN))

.PHONY: clean fclean all re run rerun