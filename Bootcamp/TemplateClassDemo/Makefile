CC = clang++
CFLAGS = -Wall -g -std=c++23
INCLUDE = -Iinclude/

SRC_DIR = src
OBJ_DIR = obj
TARGET = bin/Demo

SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
OBJECTS = $(patsubst %.o, $(OBJ_DIR)/%.o, $(OBJS))
DEPS = $(OBJECTS:.o=.d)

all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

.PHONY: clean all

clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET)
	@echo "Cleaned up. complete"

-include $(DEPS)
