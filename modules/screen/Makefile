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

MINILIBX_DIR = ../minilibx-linux
LIBFT_DIR = ../libft/inc/
LIBMAPS_DIR = ../maps/inc/
LIBERRORS_DIR = ../errors/inc/

#FILES
SRCS =	screen_utils.c \
		screen_draw_2d.c \
		screen_draw_3d_ray.c \
		screen_draw_3d_rect.c \
		screen_draw_utils.c \
		screen_skyline.c \
		screen_bloc_utils.c \
		screen_handlers.c \
		screen_tracerays.c \
		screen_config.c \
		screen_move_player.c \
		screen_player_utils.c \
		screen_rotate_player.c \

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

#INCLUDES
INCLUDES = -I$(MINILIBX_DIR) -I$(LIBFT_DIR) -I$(LIBMAPS_DIR) -I$(LIBERRORS_DIR) -I$(INC_DIR)

all: $(MINILIBX_DIR) $(OBJS_DIR) | $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
# @cp $(MINILIBX_DIR)/libmlx.a $(NAME)
	@ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re