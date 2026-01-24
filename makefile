CC := gcc
CFLAGS := -Wall -Wextra -g -O1 -MMD -MP

LIBS := -lGLEW -lGL -lglfw -lGLU -ldl -lfreetype -lm

TARGET := main
BUILD_DIR := build

SRCS := $(wildcard src/*.c)
OBJS := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEP := $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEP)

sanitize: CFLAGS += -fsanitize=address
sanitize: LDFLAGS += -fsanitize=address
sanitize: clean $(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
