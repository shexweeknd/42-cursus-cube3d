NAME = libft.a

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

#DIRS
SRCS_DIR = ./src
OBJS_DIR = ./out
INC_DIR = ./inc

#FILES
SRCS = ft_strlen.c \
		ft_putstr.c \

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

#INCLUDES
INCLUDES = -I$(INC_DIR)

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re