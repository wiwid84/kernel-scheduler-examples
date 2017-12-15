CC=gcc
CFLAGS=-Wall -Werror
OUT= other-task rr-task fifo-task

%-task: %-task.c
	@echo "Building $@"
	@$(CC) $(CFLAGS) -o $@ $<

all: $(OUT)

other: other-task
rr: rr-task
fifo: fifo-task

clean:
	@echo "Cleaning $(OUT)"
	@rm -f $(OUT)
