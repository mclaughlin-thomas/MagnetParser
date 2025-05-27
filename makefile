CC = gcc
CCFLAGS = -Wall -Werror -std=c17 -MMD -MP
LDLIBS =

SRCS = $(wildcard *.c)
HDRS = $(wildcard *.h)
OBJS = $(patsubst %.c, %.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

PROG = magnet

$(PROG): $(OBJS)
	@echo [Sources: $(SRCS)]
	@echo [Headers: $(HDRS)]
	@echo [Objects: $(OBJS)]
	@echo [Program: $(PROG)]
	$(CC) -o $@ $^ $(LDLIBS)
	# to build executable, first build all object files

%.o: %.c
	@echo [Compiling $<]
	$(CC) $(CCFLAGS) -c $< -o $@
	# to make main.o, use main.c

-include $(DEPS)

.PHONY: clean
clean:
	@echo [cleaning up]
	rm -f $(OBJS) $(PROG) $(DEPS)
.PHONY: run
run:
	@echo [executing $(PROG)]
	./$(PROG)