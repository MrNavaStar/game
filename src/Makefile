# lab09

CC=gcc
CFLAGS=-Wall -std=c11
LDFLAGS=-lm -lncursesw

game: main.o
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $^

%.o : %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $^

.PHONY:
clean:
	rm -f game *.o *~