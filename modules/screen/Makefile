#COLORS
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
NC=\033[0m

NAME = libscreen.a

CC = cc

CFLAGS = -g -Wall -Wextra -Werror

#DIRS
SRCS_DIR = ./src
OBJS_DIR = ./out
INC_DIR = ./inc

MINILIBX_DIR = ../../mlx

#FILES
SRCS = screen.c \

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

#INCLUDES
INCLUDES = -I$(MINILIBX_DIR) -I$(INC_DIR)

all: $(MINILIBX_DIR) $(OBJS_DIR) | $(NAME)

exec: all
	@$(CC) $(CFLAGS) $(INCLUDES) main.c -L./ -lscreen -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm -o screen
	@echo "$(GREEN)screen compiled$(NC)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	@cp $(MINILIBX_DIR)/libmlx.a $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) compiled$(NC)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$(NAME) obj compiled$(NC)"

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)$(NAME) obj removed$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) is totally clean$(NC)"

re: fclean all

.PHONY: all clean fclean re