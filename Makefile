# Compiler and executable
CC = g++
EXE = bin/game

# Directories
SRC_DIR = src
BIN_DIR = bin
GLM_DIR = include/others/glm
STB_IMAGE_DIR = include/others/stb_image
GLAD_DIR = include/others/glad
INCLUDE_DIR = include

# Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
GLAD_FILE = $(GLAD_DIR)/glad.c
STB_IMAGE_FILE = $(STB_IMAGE_DIR)/stb_image.c
FILES = $(GLAD_FILE) $(STB_IMAGE_FILE) $(SRC_FILES) 

# Libraries
OPENGL_LIBS = -lglfw -lGL -lm

# Include directories
INCLUDE = -I$(INCLUDE_DIR) -I$(GLM_DIR) -I$(GLAD_DIR) -I$(STB_IMAGE_DIR)

# Phony targets
.PHONY: all clean re

# Default target
all: $(EXE)
	./$(EXE)

# Build executable
$(EXE): $(FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(FILES) $(INCLUDE) -o $(EXE) $(OPENGL_LIBS)

# Clean build files
clean:
	rm -f $(EXE)

# Rebuild
re: clean all
