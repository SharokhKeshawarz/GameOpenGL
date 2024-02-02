##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC = gcc

CFLAGS = -Wall -Wextra -g

EXE = bin/game

FILES = src/*.c

LIB = -L./lib

OPENGL_LIBS = lib/glad -lGL -lcglm -lm

SFML_LIBS = -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-network

INCLUDE = -I./include

all: $(EXE)
	./$(EXE)

$(EXE):
	$(CC) $(CFLAGS) $(FILES) $(INCLUDE) $(LIB) -o $(EXE) $(OPENGL_LIBS) $(SFML_LIBS)

clean:
	rm $(EXE)

re: clean all