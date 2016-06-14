EXEC      = enigma
CC        = g++
CFLAGS    = -c -Wall -Werror -pedantic -std=c++11
LDFLAGS   =

SRC_DIR   = src
SOURCES   = $(wildcard $(SRC_DIR)/*.cpp)

OBJ_DIR   = bin
OBJECTS = $(patsubst src/%.cpp, bin/%.o, $(SOURCES)) 

.PHONY: all clean

all: pre-build $(SOURCES) $(EXEC)

pre-build:
	mkdir -p $(OBJ_DIR)/
	
$(EXEC): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)
