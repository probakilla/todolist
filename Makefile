CC = gcc
CFLAGS = -std=c99 -W -Wall -ansi -pedantic
LDFLAGS = -I includes/
BIN = todolist
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

all: $(BIN)

$(BIN): $(OBJ) main.o
	$(CC) -o $(BIN) $^ $(LDFLAGS)

main.o: main.c includes/user.h
	$(CC) -o $@ -c $< $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean

clean:
	rm -rf *.o
	rm -rf $(BIN)
