# lab09

CC=gcc
CFLAGS=-Wall -std=c11
LDFLAGS=-lm -lncursesw -ltinfo

game:
	cd src
	make

.PHONY:
clean:
	cd src
	rm -f game *.o *~