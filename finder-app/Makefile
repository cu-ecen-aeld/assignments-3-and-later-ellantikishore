ifdef CROSS_COMPILE
	CC=$(CROSS_COMPILE)gcc
else
	CC=gcc
endif

all: writer

writer: writer.c
	$(CC) -g -Wall -o writer writer.c -I.

.PHONY: clean

clean:
	rm -rf writer
