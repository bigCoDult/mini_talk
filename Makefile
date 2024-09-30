CLIENT = client
SERVER = server
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0
RM = rm -rf
LIBFT_DIR = ./libft
LDFLAGS = -L$(LIBFT_DIR) -lft
LIBFT = $(LIBFT_DIR)/libft.a
INC = -I$(LIBFT_DIR)

SRC = \
			client.c \
			server.c \

OBJ = $(SRC:.c=.o)

all: $(CLIENT) $(SERVER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(CLENT): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(CLIENT)

$(SERVER): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(SERVER)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	$(RM) $(CLENT) $(SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
