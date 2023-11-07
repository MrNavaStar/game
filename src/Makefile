# Ethan Stevenson, 3131095, lab07

CC=gcc
CFLAGS=-Wall -std=c11
LDFLAGS=-lm

exec: test_pointerFun.o pointerFun.o pointerFun.h
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $^

%.o : %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $^

.PHONY:
clean:
	rm -f exec *.o *~