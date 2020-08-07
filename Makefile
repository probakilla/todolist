CC = gcc
CFLAGS = -std=c99 -W -Wall -ansi -pedantic
LDFLAGS =
BIN = todolist
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $(BIN) $^ $(LDFLAGS)

main.o: user.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean

clean:
	rm -rf *.o
	rm -rf $(BIN)
