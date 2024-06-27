CC = clang++
CFLAGS = -Wall -g -std=c++23
LDFLAGS =
USE_SYSTEMD = 1
INCLUDE = -Iinclude/

# Source file directory
SRC_DIR = src

# Object files
OBJ_DIR = obj
TARGET = bin/DemoA

SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
OBJECTS = $(patsubst %.o, $(OBJ_DIR)/%.o, $(OBJS))
DEPS = $(OBJECTS:.o=.d)

all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ -MD $(LDFLAGS)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)


.PHONY: clean all
clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET)
	@echo "Cleanup complete!"

-include $(DEPS)
