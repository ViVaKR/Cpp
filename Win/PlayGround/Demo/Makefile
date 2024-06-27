ifeq ($(ShellId), Microsoft.PowerShell)
SHELL := pwsh
.SHELLFLAGS := -Command
endif

CC = clang++
CFLAGS = -Wall -g -std=c++23
LDFLAGS =
USE_SYSTEMD = 1
INCLUDE = -Iinclude/

SRC_DIR = src

# Object files
OBJ_DIR = obj
TARGET = bin/Demo.exe

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

	@pwsh -c "Remove-Item -Path $(OBJECTS) -Recurse -Force -ErrorAction SilentlyContinue"
	@pwsh -c "Remove-Item -Path $(DEPS) -Recurse -Force -ErrorAction SilentlyContinue"
	@pwsh -c "Remove-Item -Path $(TARGET) -Recurse -Force -ErrorAction SilentlyContinue"
	@pwsh -c "Write-Host 'Success Remove Items!'"

-include $(DEPS)

remove:

	@pwsh -c "Invoke-Command -ScriptBlock { & { \
				Remove-Item -Path $(OBJECTS) -Recurse -Force -ErrorAction SilentlyContinue && \
				Remove-Item -Path $(DEPS) -Recurse -Force -ErrorAction SilentlyContinue && \
				Remove-Item -Path $(TARGET) -Recurse -Force -ErrorAction SilentlyContinue \
			} \
		}"
test:
	@echo hello
	@pwsh -c if(3 -eq 1) \
	{ echo world } \
	else \
	{ echo false }