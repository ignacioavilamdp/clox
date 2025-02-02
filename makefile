# Directories
BUILD_DIR := ./build
SRC_DIRS := ./src

# Compiler command and compiler flags
CC = gcc
CFLAGS = -Wall

# Target executable
TARGET_EXEC = main.exe

# Source files
SRC_FILES := chunk.c memory.c main.c debug.c value.c

# Object files
OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Rule to build the target executable
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIRS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
.PHONY: clean
clean:
	del /Q .\build