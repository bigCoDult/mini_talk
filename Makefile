CLIENT = client
SERVER = server
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0
RM = rm -rf
LIBFT_DIR = ./libft
LDFLAGS = -L$(LIBFT_DIR) -lft
LIBFT = $(LIBFT_DIR)/libft.a
INC = -I$(LIBFT_DIR)

SRC_SERVER = \
							server.c \

SRC_CLIENT = \
							client.c \

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(SERVER): $(LIBFT) $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LDFLAGS) -o $(SERVER)

$(CLIENT): $(LIBFT) $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LDFLAGS) -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
