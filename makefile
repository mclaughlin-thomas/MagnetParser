CC = gcc
CCFLAGS = -Wall -Werror -std=c17 -MMD -MP
LDLIBS =

SRCS = $(wildcard *.c)
HDRS = $(wildcard *.h)
BUILD_DIR = build
OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS = $(patsubst %.c,$(BUILD_DIR)/%.d,$(SRCS))

PROG = magnet

# Create build directory if it doesn't exist
$(shell mkdir -p $(BUILD_DIR))

# to build executable, first build all object files
$(PROG): $(OBJS)
	@echo [Sources: $(SRCS)]
	@echo [Headers: $(HDRS)]
	@echo [Objects: $(OBJS)]
	@echo [Program: $(PROG)]
	$(CC) -o $@ $^ $(LDLIBS)

# to make main.o, use main.c
$(BUILD_DIR)/%.o: %.c
	@echo [Compiling $<]
	$(CC) $(CCFLAGS) -c $< -o $@

-include $(DEPS)

.PHONY: clean
clean:
	@echo [cleaning up]
	rm -rf $(BUILD_DIR) $(PROG)
.PHONY: run
run:
	@echo [executing $(PROG)]
	./$(PROG)