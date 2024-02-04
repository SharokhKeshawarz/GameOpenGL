##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Builds Game
##

EXE    = bin/game

CC      = gcc

CFLAGS = -Wall -Wextra -g

SRC     = $(shell find src -type f -name '*.c')

OBJ     = $(SRC:.c=.o)

LIB = -L./lib 

INCLUDE = -I./include

LIBFLAGS = lib/glad -lGL -lglfw3 -lcglm -lm -lX11

all: $(EXE)

$(EXE): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(INCLUDE) $(LIB) -o $(EXE) $(LIBFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXE)

re: fclean all