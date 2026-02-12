CC = clang
CFLAGS = -O2 -Wall -Wextra
SRC_DIR = ./src
BIN_DIR = ./bin
BIN_NAME = phantom_type

all: build
	@echo build successful!

run: build
	@$(BIN_DIR)/$(BIN_NAME)

build: bin-dir
	@$(CC) $(CFLAGS) $(SRC_DIR)/main.c -o $(BIN_DIR)/$(BIN_NAME)

bin-dir:
	@mkdir -p $(BIN_DIR)
