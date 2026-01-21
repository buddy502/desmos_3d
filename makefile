CC := gcc
CFLAGS := -Wall -Wextra -g -O2 -I. -Iinclude -I/usr/include/freetype2 -MMD -MP

LIBS := -lGLEW -lGL -lglfw -lGLU -ldl -lfreetype -lm

TARGET := main
BUILD_DIR := build

SRCS := $(wildcard src/*.c)
OBJS := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEP := $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $@

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEP)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

