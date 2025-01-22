#COLORS
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
NC=\033[0m

NAME = libscreen.a

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

#DIRS
SRCS_DIR = ./src
OBJS_DIR = ./out
INC_DIR = ./inc

MINILIBX_DIR = ../../minilibx-linux

#FILES
SRCS = screen.c \

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

#INCLUDES
INCLUDES = -I$(MINILIBX_DIR) -I$(INC_DIR)

all: $(MINILIBX_DIR) $(OBJS_DIR) | $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) compiled$(NC)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)$(NAME) obj compiled$(NC)"

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)$(NAME) obj removed$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) is totally clean$(NC)"

re: fclean all

.PHONY: all clean fclean re