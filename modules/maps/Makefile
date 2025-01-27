#COLORS
RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
NC=\033[0m

NAME = libmaps.a

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

#DIRS
SRCS_DIR = ./src
OBJS_DIR = ./out
INC_DIR = ./inc

LIBFT_DIR = ../libft/inc/
ERRORS_DIR = ../errors/inc/

#FILES
SRCS = maps.c \
		map_utils.c \
		map_middleware.c \

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

#INCLUDES
INCLUDES = -I$(ERRORS_DIR) -I$(LIBFT_DIR) -I$(INC_DIR)

all: $(OBJS_DIR) | $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re