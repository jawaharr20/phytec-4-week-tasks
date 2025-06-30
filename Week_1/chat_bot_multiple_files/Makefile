CC = gcc
CFLAGS = -Wall -g
LDFLAGS =

# Source files
COMMON_SRC = queue.c state_machine.c
SERVER_SRC = udp_chatbot_server.c
CLIENT_SRC = udp_chatbot_client.c

# Object files
COMMON_OBJ = $(COMMON_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# Executables
SERVER = udp_chatbot_server
CLIENT = udp_chatbot_client

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(COMMON_OBJ)
	$(CC) $(SERVER_OBJ) $(COMMON_OBJ) -o $@ $(LDFLAGS)

$(CLIENT): $(CLIENT_OBJ) $(COMMON_OBJ)
	$(CC) $(CLIENT_OBJ) $(COMMON_OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SERVER) $(CLIENT) *.o

.PHONY: all clean
