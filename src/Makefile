# lab09

CC=gcc
CFLAGS=-Wall -std=c11
LDFLAGS=-lm -lncursesw -ltinfo

game: main.o screens.o levels.o headers/screens.h headers/levels.h
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $^

%.o : code/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $^

.PHONY:
clean:
	rm -f game *.o *~
