# lab09

CC=gcc
CFLAGS=-Wall -std=c11
LDFLAGS=-lm -lncursesw -ltinfo

game: main.o screens.o screens.h levels.o
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $^

%.o : %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $^

.PHONY:
clean:
	rm -f game *.o *~
